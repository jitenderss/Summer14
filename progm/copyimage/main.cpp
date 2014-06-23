#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if(argc !=2)
    {
     cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image,dst,src;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    dst.create( image.size(), image.type() );
    dst=Scalar::all(0);
    image.copyTo(dst);
    Canny(image,src,50,150,3);
    /*blur( image, src, Size(3,3) );
    imshow("blur",src); */


    if(! image.data)
    {
      cout << "Could not open or find the image"<< endl;
      return -1;
    }
    
    namedWindow("Display window", CV_WINDOW_AUTOSIZE);
    imshow("Display Window",dst);
 
    waitKey(0);
    return 0;
}




















