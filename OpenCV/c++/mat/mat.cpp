#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat A = Mat::eye(4,4,CV_32SC1);
	Mat B = A * 3 + 1;
	Mat C = B.diag(0) + B.col(1);
	
	cout << "A:" << endl;
	cout << A << endl;
	cout << "B:" << endl;
	cout << B << endl;
	cout << "B.diag(0)" << endl;
	cout << B.diag(0) << endl;
	cout << "B col(1):" << endl;
	cout << B.col(1) << endl;
	cout << "C:" << endl;
	cout << C << endl;
	
	return 0;
}
