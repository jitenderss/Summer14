 cmake_minimum_required(VERSION 2.8)
project(ar_jitendra_testproject)
SET(CMAKE_MODULE_PATH ${CMAKE_INSTALL_PREFIX}/lib/cmake/ )
find_package(aruco REQUIRED )
add_executable(aruco_simple aruco_simple.cpp)
target_link_libraries(aruco_simple  ${aruco_LIBS})

add_executable(aruco_simple_video aruco_simple_video.cpp)
target_link_libraries(aruco_simple_video  ${aruco_LIBS})
