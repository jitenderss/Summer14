#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cv.h>  
#include <highgui.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if(argc !=2)
    {
     cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image,hsv,binary,src;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    cvtColor(image, hsv, CV_BGR2HSV);
	/*imshow("HSV",hsv);*/
   inRange(hsv, Scalar(157, 72, 156), Scalar(180, 169, 255), binary);
	    imshow("BINARY",binary);
      Canny(binary,src,50,150,3);
   
    /*if(! image.data)
    {
      cout << "Could not open or find the image"<< endl;
      return -1;
    }*/
    
    namedWindow("Display window", CV_WINDOW_AUTOSIZE);
    imshow("Display Window",src);
 
    waitKey(0);
    return 0;
}




















