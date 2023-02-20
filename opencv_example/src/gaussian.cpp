#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 튜토리얼 : https://www.opencv-srf.com/p/introduction.html
// Kernel을 통한 블러 처리
int main()
{
    Mat img = imread("../hello_world.png");
    Mat new_img, new_img2;

    if(img.empty())
    {
        std::cout<<"Can't find image" << std::endl;
        std::cout<<"please press any key and enter" << std::endl;
        std::cin.get();
        return -1;
    }

	auto name = "origin";
	namedWindow(name);
    imshow(name, img);

    /*
        GaussianBlur(input, output, size, sigmaX) : 가우시안 블러 효과를 적용시키는 함수
            - input : 입력 이미지
            - output : 출력 이미지
            - size : 커널 사이즈
            - sigmaX : 가우시안 함수에서 시그마 x에 대한 변수 값
    */

    Mat kernel3, kernel5;

    GaussianBlur(img, kernel3, Size(3,3), 0);
    auto name3 = "3x3";
    namedWindow(name3);
    imshow(name3, kernel3);

    GaussianBlur(img, kernel5, Size(5,5), 0);
    auto name5 = "5x5";
    namedWindow(name5);
    imshow(name5, kernel5);

    waitKey();
    destroyAllWindows();
}