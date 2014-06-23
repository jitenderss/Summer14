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
   inRange(hsv, Scalar(10, 16, 198), Scalar(35, 255, 255), binary);//yellow color detection
	    imshow("BINARY",binary);
      Canny(binary,src,50,150,3);//edge detection
   
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




















