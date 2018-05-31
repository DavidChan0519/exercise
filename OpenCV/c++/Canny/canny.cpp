#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
	Mat img = imread(argv[1], 0);
	if (img.empty()) {
		cout << "load pic failed" << endl;
		return -1;
	}
	
	Mat result;
	Canny(img, result, 50, 100);
	
	imwrite("canny.png", result);
	namedWindow("sketch", CV_WINDOW_NORMAL);
	imshow("sketch", result);
	waitKey(0);
	return 0;
}

