#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cv.h>  
#include <highgui.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if(argc !=2)
    {
     cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }
    int thresh=500;
    RNG rng(12345);
    Mat image,hsv,binary,src_gray;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    cvtColor(image, hsv, CV_BGR2HSV);
	/*imshow("HSV",hsv);*/
    inRange(hsv, Scalar(157, 72, 156), Scalar(180, 169, 255), binary);
     /* cvtColor( hsv, src_gray, CV_BGR2GRAY );
  blur( src_gray, src_gray, Size(3,3) );
	   imshow("BINARY",binary);
   
    if(! image.data)
    {
      cout << "Could not open or find the image"<< endl;
      return -1;
    }
    
    namedWindow("Display window", CV_WINDOW_AUTOSIZE);
    imshow("Display Window",image);*/
   Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( binary, canny_output, thresh, thresh*3, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
     }
   namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );
 
    waitKey(0);
    return 0;
}




















