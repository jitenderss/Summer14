cmake_minimum_required(VERSION 2.8)
project( Video )
find_package( OpenCV REQUIRED )
add_executable( video main.cpp )
target_link_libraries( video ${OpenCV_LIBS} )

