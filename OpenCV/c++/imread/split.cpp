// g++ -std=c++11 -Wall -L/usr/local/lib -O2 -g -o test test.cpp -lopencv_core -lopencv_imgcodecs -lopencv_imgproc
#include <fstream>
#include <iostream>
#include <streambuf>
#include <sys/time.h>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << " Usage: " << argv[0] << " <file>" << endl;
        exit(1);
    }
    cv::Mat img = cv::imread(argv[1]);
    cout << "channel num:"<<img.channels()<<endl;
    cv::imshow("org",img);
    cv::Mat channel[3];
    cv::split(img, channel);
    cv::imshow("channel 0:",channel[0]);
    cv::imshow("channel 1:",channel[1]);
    cv::imshow("channel 2:",channel[2]);
    cv::waitKey(0);
    return 0;
}

