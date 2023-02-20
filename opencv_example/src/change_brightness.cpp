#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 튜토리얼 : https://www.opencv-srf.com/p/introduction.html
// convertTo()함수를 이용한 밝기 조절 튜토리얼
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
    auto new_name = "change pixel brightness";
    auto new_name2 = "change alpha";

    namedWindow(name);
    imshow(name, img);
    waitKey(0);
    destroyWindow(name);

    /*
        convertTo(output_array, type, alpha, beta) : 이미지의 밝기 값을 변경 시켜주는 함수
            - output_array : 출력값
            - type : 출력 이미지의 타입(음수면 입력 이미지와 동일한 타입)
            - alpha : 입력 이미지의 픽셀마다 곱해주는 값(밝기 조절)
            - beta : 입력 이미지의 픽셀마다 더해주는 값(밝기 조절)
    */ 

    img.convertTo(new_img, -1, 1, 50);              // 이미지의 픽셀 밝기 값을 추가 pixel + beta

    namedWindow(new_name);
    imshow(new_name, new_img);
    waitKey(0);
    destroyWindow(new_name);

    img.convertTo(new_img2, -1, 5, 0);              // 이미지의 alpha 값을 변경 pixel*alpha

    namedWindow(new_name2);
    imshow(new_name2, new_img2);
    waitKey(0);
    destroyWindow(new_name2);
}