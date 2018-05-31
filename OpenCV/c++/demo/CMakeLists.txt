cmake_minimum_required(VERSION 2.8)
project( DisplayImage )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( Display_Image DisplayImage.cpp)
target_link_libraries( Display_Image ${OpenCV_LIBS} )

install(TARGETS Display_Image DESTINATION bin)
