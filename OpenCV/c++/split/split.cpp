#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;


int main()
{
    char d[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    cv::Mat m(2, 2, CV_8UC3, d);
    cout << "m:"<<endl;
    cout << m << endl;

    cv::Mat channels[3];
    cv::split(m, channels);
    cout << "channels:"<<endl;
    cout <<channels[0]<<endl;
    cout <<channels[1]<<endl;
    cout <<channels[2]<<endl;
}
