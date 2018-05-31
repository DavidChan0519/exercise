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

    string file(argv[1]);
    ifstream in(argv[1]);
    if (!in.good()) {
        cout << "file '" << argv[1] << "' doesn't exist" << endl;
        exit(2);
    }

    string s((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    std::vector<char> pic(s.c_str(), s.c_str() + s.length());
    cv::Mat image;
    cv::imdecode(pic, CV_LOAD_IMAGE_GRAYSCALE , &image);
    cv::imwrite("out1.jpg", image);

    cv::Mat save = cv::imread("out1.jpg");
    cv::imwrite("out2.jpg", save);

    return 0;
}

