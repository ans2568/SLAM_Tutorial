#include <iostream>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
    Mat img;                          // opencv cv::Mat 클래스 이미지 및 행렬을 표현할 때 사용
    img = imread("../hello.png");     // imread(std::String path) path에 적힌 이미지 읽어와 cv::Mat으로 변환, 뒤에 flag를 추가하면 이미지를 읽어오는 모드를 정할 수 있음
    imshow("Hello, World!", img);     // imshow(std::String title, cv::Mat img) title에 해당하는 새로운 창 생성 및 img 이미지를 표시
    waitKey(0);                       // 키 입력을 기다리는 함수 0을 넣을 시 forever
}