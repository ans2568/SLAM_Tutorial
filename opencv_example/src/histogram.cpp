#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 튜토리얼 : https://www.opencv-srf.com/p/introduction.html
// 이미지에서 비슷한 픽셀값을 갖는 픽셀들을 동일하게 만들고 히스토그램화 시켜 보여주는 튜토리얼
// cvtColor() 함수로 이미지 변환 튜토리얼
int main()
{
	Mat img = imread("../picture/hello_world.png");
	Mat new_img, new_img2;

	if (img.empty())
	{
		std::cout << "Can't find image" << std::endl;
		std::cout << "please press any key and enter" << std::endl;
		std::cin.get();
		return -1;
	}

	auto name = "origin";
	namedWindow(name);
    imshow(name, img);

	/*
		cvtColor(image, output_image, flag) : 3채널 이미지를 다른 형식으로 변경시켜주는 함수(BGR -> RGB)
			- image : 입력 이미지
			- output_image : 출력 이미지
			- flag : 변경시킬 내용(ex. COLOR_BGR2RGB)
	*/
	cvtColor(img, new_img, COLOR_BGR2YCrCb);

	auto new_name = "convert image to BGR->YCrCb";
	namedWindow(new_name);
    imshow(new_name, new_img);

	/*
		equalizeHist(image, output_image) : 입력 이미지의 각 픽셀 값들의 개수를 비슷한 애들끼리 통일화 시켜주는 함수
			 - image: 입력 이미지(입력 이미지는 GRAYSCALE 이미지이어야 함)
			 - output_image : 출력 이미지

		 	참조 : https://www.opencv-srf.com/2018/02/histogram-equalization.html
	*/
	cvtColor(img, new_img2, COLOR_BGR2GRAY);
	equalizeHist(new_img2, new_img2);

	auto new_name2 = "histogram image";
	namedWindow(new_name2);
    imshow(new_name2, new_img2);

	/*
		split(input_image, output_image_vector) : n차원 입력 이미지를 n차원 이미지 벡터로 변환해주는 함수
			- input_image : 입력 이미지
			- output_image_vector : 입력 이미지의 차원을 토대로 n개의 원소를 가진 Mat 타입의 벡터
	*/
	std::vector<Mat> vec;
	split(new_img, vec);

	equalizeHist(vec[0], vec[0]);

	auto new_name3 = "histogram image2";
	namedWindow(new_name3);
    imshow(new_name3, vec[0]);

	/*
		merge(vector, image) : 각 채널의 벡터를 합쳐서 n채널의 이미지로 변환시켜주는 함수
			- vector : 각 이미지 벡터
			- image : 벡터들을 합쳐서 얻은 n채널 이미지
	*/
	merge(vec, new_img);
	cvtColor(new_img, new_img, COLOR_YCrCb2BGR);
	auto new_name4 = "changed image";
	namedWindow(new_name4);
    imshow(new_name4, new_img);

    waitKey(0);

	destroyAllWindows();
}