#!/bin/sh
g++ -std=c++11 -Wall -L/usr/local/lib -O2 -g -o test imread.cpp -lopencv_core -lopencv_imgcodecs
g++ -Wall -O2 -g resize.cpp -o test_opencv -L/usr/local/lib -rdynamic -lopencv_imgproc -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio
g++ -std=c++11 -Wall -L/usr/local/lib -O2 -g -o split split.cpp -lopencv_imgproc -lopencv_core -lopencv_highgui -lopencv_imgcodecs
