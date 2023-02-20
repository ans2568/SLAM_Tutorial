#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;


// 튜토리얼 : https://www.opencv-srf.com/p/introduction.html
// 이미지 읽고 보여주기 튜토리얼
int main()
{
    /*
        imread(path, flag) : 경로에 해당하는 이미지를 읽는 함수
            - path : 경로
            - flag : 이미지를 어떤 형식으로 읽을 지
                - IMREAD_UNCHANGED : alpha channel을 지원한다면 해당 내용까지 그대로 읽어오기
                - IMREAD_GRAYSCALE : 그레이스케일로 읽어오기
                - IMREAD_COLOR : BGR 형태로 읽어오기(3채널)

        namedWindow(name) : 이미지에 해당하는 창을 생성하는 함수
            - name : 이미지에 해당하는 이름
        
        imshow(name, image) : 이미지를 보여주는 함수
            - name : 창 제목으로 띄워질 이름
            - image : 보여줄 이미지
        
        waitKey(flag) : 키 입력을 기다리는 함수
            - flag : 단위는 ms이고 0일 경우 무한정 키 입력까지 기다림

        destroyWindow(name) : namedWindow로 인해 생성된 window나 imshow(name, image)를 통해 생성된 window의 name을 토대로 제거해주는 함수
            - name : 창 제목
    */
    Mat img = imread("../hello_world.png");
    auto name = "hello, world";
    namedWindow(name);
    imshow(name, img);
    waitKey(0);
    destroyWindow(name);
}