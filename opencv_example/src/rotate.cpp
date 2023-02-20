#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

// 튜토리얼 : https://www.opencv-srf.com/p/introduction.html
// 이미지를 회전시키는 튜토리얼
int main()
{
    Mat img = imread("../hello_world.png");

    if(img.empty())
    {
        std::cout<<"Can't find image" << std::endl;
        std::cout<<"please press any key and enter" << std::endl;
        std::cin.get();
        return -1;
    }
    auto name = "origin";
    auto new_name = "Rotated Image";

    namedWindow(name);
    imshow(name, img);

    /*
        getRotationMatrix2D(Point, angle, scale) : 입력 이미지를 회전시키는 함수
            - Point : 이미지의 중간 픽셀의 좌표 (image.rows/2, image.cols/2)
            - output : 회전시킬 각도
            - size : 스케일 사이즈
    */
    int center_x = img.rows/2;
    int center_y = img.cols/2;

    auto rotationMatrix2d = getRotationMatrix2D(Point(center_x, center_y), 30, 1);

    Mat rotated_img;
    warpAffine(img, rotated_img, rotationMatrix2d, img.size());

    namedWindow(new_name);
    imshow(new_name, rotated_img);

    waitKey(0);
    destroyAllWindows();
}