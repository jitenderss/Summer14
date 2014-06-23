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

    Mat image,hsv,binary,src,eroded,dilated;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    cvtColor(image, hsv, CV_BGR2HSV);
	/*imshow("HSV",hsv);*/
   //inRange(hsv, Scalar(40, 44, 101), Scalar(99, 255, 255), binary);	//green
inRange(hsv, Scalar(110,100, 109), Scalar(138, 255, 255), binary);	//purple
	    imshow("BINARY",binary);
      Canny(binary,src,50,150,3);
cv::Mat element(7,7,CV_8U,cv::Scalar(1));
        cv::erode(binary,eroded,element);
	imshow("eroded",eroded);
	cv::Mat elements(7,7,CV_8U,cv::Scalar(1));
         cv::dilate(binary,dilated,elements);
	imshow("dilated",dilated);
   
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




















