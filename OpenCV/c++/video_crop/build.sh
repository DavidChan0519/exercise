#!/bin/sh
g++ video_crop.cpp -o video_crop -std=c++11 -L/usr/local/lib  -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgproc
