# If Player isn't installed to /usr, you'll have to edit this path to point
# to the location of UserPlayerC++.cmake and UsePlayerPlugin.cmake
#SET (CMAKE_MODULE_PATH "/usr/local/share/cmake/Modules")
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT (playerstagetest)
SET(PROJECT_VERSION 0.0.1 CACHE STRING "CMake Example Project Version Number")
set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall ")
set(CMAKE_C_FLAGS_RELEASE "-O2 ")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall ")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 ")
SET (CMAKE_MODULE_PATH "/usr/local/share/cmake/Modules")

INCLUDE (UsePlayerC++)
INCLUDE (UsePlayerPlugin)
FIND_PACKAGE( OpenCV REQUIRED)
find_package(aruco REQUIRED )
include_directories(  ${aruco_INCLUDE_DIRS}  ${OpenCV_INCLUDE_DIRS} )
#set(HEADER_FILES /home/jitender/playrstge/firstprgm/ar_omp.h /home/jitender/playrstge/firstprgm/aruco.h /home/jitender/playrstge/firstprgm/arucofidmarkers.h /home/jitender/playrstge/firstprgm/cameraparameters.h /home/jitender/playrstge/firstprgm/chromaticmask.h /home/jitender/playrstge/firstprgm/common.h /home/jitender/playrstge/firstprgm/cvdrawingutils.h /home/jitender/playrstge/firstprgm/exports.h /home/jitender/playrstge/firstprgm/marker.h /home/jitender/playrstge/firstprgm/markerdetector.h /home/jitender/playrstge/firstprgm/subpixelcorner.h)
add_executable (test test.cpp ${HEADER_FILES})
#add_executable(test test.cpp)
target_link_libraries(test  ${aruco_LIBS})
target_link_libraries( test ${OpenCV_LIBS} )
PLAYER_ADD_PLAYERCPP_CLIENT (test SOURCES test.cpp LIBDIRS ${OpenCV_LIBS} ${aruco_LIBS}) 
# These files include macros that make building against Player easier.  They provide
# the PLAYER_ADD* macros
#INCLUDE (UsePlayerC++)
#INCLUDE (UsePlayerPlugin)

# This command adds an example PlayerC++ client called 'exampleclient', using
# the 'exampleclient.cc' source file.
#PLAYER_ADD_PLAYERCPP_CLIENT (test SOURCES test.cpp)

# You can install the example client system-wide, using the INSTALL command.  The
# path is relative to CMAKE_INSTALL_PREFIX which defaults to /usr/local.  This will
# install the exampleclient to /usr/local/bin
#INSTALL(exampleclient bin)

# If you also want to include a Player plugin driver, use these directions:
# This command adds an example plugin driver which will be called 'libexampledriver.so'
# which uses the source file 'exampleplugin.cc'
# PLAYER_ADD_PLUGIN_DRIVER (exampledriver SOURCES exampleplugin.cc)

