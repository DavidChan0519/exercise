#!/bin/sh

g++ Main.cpp -o mythread -pthread -std=c++11
./mythread
