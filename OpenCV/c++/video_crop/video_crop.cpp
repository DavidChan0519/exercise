#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Please specify video file." << endl;
        exit(-1);
    }
    const string file = argv[1];
    VideoCapture inputVideo(file);

    if (!inputVideo.isOpened())
    {
        cout  << "Could not open the input video for write: " << endl;
        return -1;
    }

    //Get sizes of frames
    //Size S = Size(inputVideo.get(CV_CAP_PROP_FRAME_WIDTH),
    //  inputVideo.get(CV_CAP_PROP_FRAME_HEIGHT));

    //make a video writer and initialize it at 30 FPS
    VideoWriter outputVideo;
    outputVideo.open("test.avi",CV_FOURCC('H', '2', '6', '4') , 30, Size(900,600), false);
    if (!outputVideo.isOpened())
    {
        cout  << "Could not open the output video for write: " << endl;
        return -1;
    }
    namedWindow("video");
    namedWindow("crop_video");

    //ROI
    Rect box;
    box.width = 130;
    box.height = 300;
    box.x = 0;
    box.y = 300;

    while(char(waitKey(1)) != 'q' && inputVideo.isOpened())
    {
        Mat frame;
        inputVideo >> frame;
        // check if video is over
        if (frame.empty())
        {
            cout << "video over" << endl;
            break;
        }
        Mat crop(frame,box);
        outputVideo << crop;
        imshow("video",frame);
        imshow("crop_video",crop);

    }
    return 0;
}

