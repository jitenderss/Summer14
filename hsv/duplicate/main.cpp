#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cv.h>  
#include <highgui.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    VideoCapture cap(1);     // get 'any' cam
    while( cap.isOpened() )   // check if we succeeded
    {
        Mat frame;
        if ( ! cap.read(frame) )
            break;


    Mat hsv,binary,src;
    
    cvtColor(frame, hsv, CV_BGR2HSV);
	/*imshow("HSV",hsv);*/
   inRange(hsv, Scalar(157, 72, 156), Scalar(180, 169, 255), binary);
	    imshow("BINARY",binary);
      int k = waitKey(33);
        if ( k==27 )
            break;
         
    /*if(! image.data)
    {
      cout << "Could not open or find the image"<< endl;
      return -1;
    }*/
    
  
   
 	}
    
    return 0;
}




















