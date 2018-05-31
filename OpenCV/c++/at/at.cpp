#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() 
{
	Mat grayim(600, 800, CV_8UC1);
	Mat colorim(600, 800, CV_8UC3);

	for (int i=0; i < grayim.rows; i++) {
		for (int j=0; j < grayim.cols; j++) {
			grayim.at<uchar>(i,j) = (i+j)%255;
		}
	}

	for (int i=0; i < colorim.rows; i++) {
		for (int j=0; j < colorim.cols; j++) {
			Vec3b pixel;
			pixel[0] = i % 255;
			pixel[1] = j % 255;
			pixel[2] = 0;
			colorim.at<Vec3b>(i,j) = pixel;
		}
	}

	imshow("grayim", grayim);
	imshow("colorim", colorim);
	waitKey(0);
	return 0;
}
