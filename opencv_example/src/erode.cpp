#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 튜토리얼 : https://www.opencv-srf.com/p/introduction.html
// 이미지를 Erode 시키는 튜토리얼
// 참조 : https://www.opencv-srf.com/2018/01/erode-images-and-videos.html
int main()
{
    Mat img = imread("../picture/hello_world.png");
    Mat new_img, new_img2;

    if(img.empty())
    {
        std::cout<<"Can't find image" << std::endl;
        std::cout<<"please press any key and enter" << std::endl;
        std::cin.get();
        return -1;
    }
    auto name = "origin";
    auto new_name = "3x3 erode";
    auto new_name2 = "5x5 erode";

    namedWindow(name);
    imshow(name, img);

    /*
        erode(input_img, output_img, input_kernel) : 커널에 맞게 erode하는 함수
            - input : 입력 이미지
            - output : 출력 이미지
            - size : 커널 사이즈
    */ 
    erode(img, new_img, getStructuringElement(MORPH_RECT, Size(3,3)));

    namedWindow(new_name);
    imshow(new_name, new_img);

    erode(img, new_img2, getStructuringElement(MORPH_RECT, Size(5,5)));

    namedWindow(new_name2);
    imshow(new_name2, new_img2);

    waitKey(0);
    destroyAllWindows();
}