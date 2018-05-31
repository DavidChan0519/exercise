#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	CvMLData mlData; 
	mlData.read_csv("train.csv");
	
	Mat data = cv::Mat(mlData.get_values(), true);  
    	
	cout << "Data have been read successfully!" << endl;  
	cout << "Content : "<< endl;
	cout << data << endl;
	
	return 0;
}
