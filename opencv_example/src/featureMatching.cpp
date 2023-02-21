#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/calib3d.hpp>
using namespace cv;

int main()
{
    Mat img = imread("../picture/puppy.png");
    Mat rotate_img = imread("../picture/rotated_puppy_only.png");
    // Mat rotate_img = imread("../puppy_only.png");

    if(img.empty() || rotate_img.empty())
    {
        std::cout<<"Can't find image" << std::endl;
        std::cout<<"please press any key and enter" << std::endl;
        std::cin.get();
        return -1;
    }
    
    Ptr<FeatureDetector> detector = ORB::create();              // ORB detector 생성
    std::vector<KeyPoint> keypoint, keypoint2;                  // keypoint 선언
    Mat desc, desc2;                                            // descriptor 선언
    detector->detectAndCompute(img, noArray(), keypoint, desc); // 이미지로부터 keypoint와 descriptor를 추출
    detector->detectAndCompute(rotate_img, noArray(), keypoint2, desc2);    // 이미지로부터 keypoint와 descriptor를 추출

    Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);   // Hamming distance를 사용하는 BruteForce matcher 선언
    std::vector<std::vector<DMatch>> matches;                   // 매칭된 특징점 선언
    
    // knn(K-Nearest Neighbors)를 이용한 매칭점 2개를 matches에 저장(2차원 배열)
    // 2개의 매칭점을 추출하는데 첫 번째 원소가 Best Match, 두 번째 원소가 Second Best Match이다.
    matcher->knnMatch(desc, desc2, matches, 2);
    
    std::vector<DMatch> good;                         // 더 좋은 매칭점을 찾기 위한 DMatch타입 good 변수 선언
    for (const auto& m : matches)                     // for문으로 2차원 배열로 된 매칭점에서 거리에 따라 good에 넣어준다.
    {
        if(m[0].distance<0.75 * m[1].distance)        // Best Match가 Second Best Match보다 0.75배 작을 경우 더 좋은 매칭점으로 간주
            good.push_back(m[0]);
    }

    std::vector<Point2f> pts1, pts2;
    for(const auto& match : good)
    {
        pts1.push_back(keypoint[match.queryIdx].pt);    // 매칭점에 해당하는 index를 keypoint에 적용 후 해당 Point를 벡터에 넣는다.
        pts2.push_back(keypoint2[match.queryIdx].pt);
    }

    auto H = findHomography(pts1, pts2, RANSAC, 5.0);   // Homography Matrix를 keypoint들의 Point 좌표와 RANSAC을 이용해 계산한다.
    Mat transformed_img;
    warpPerspective(img, transformed_img, H, transformed_img.size());   // Homography Matrix를 이용한 warpping을 원본 이미지에 진행한다.
    
    Mat img_matches;
    drawMatches(img, keypoint, rotate_img, keypoint2, good, img_matches);   // 원본 이미지 1과 2에 해당하는 키 포인트들과 매칭점들을 보여준다.
    imshow("match", img_matches);
    waitKey();

    imwrite("../picture/output.png", img_matches);
}