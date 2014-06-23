#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace cv;
using namespace std;
int thresh=40;
RNG rng(12345);
int main( int argc, char** argv )
{
  Mat binary,binary2,combine,hsv;
 VideoCapture cap(1);     // get 'any' cam
    while( cap.isOpened() )   // check if we succeeded
    {
        Mat src;
        if ( ! cap.read(src) )
            break;

	cvtColor(src, hsv, CV_BGR2HSV);
	imshow("src",src);
	inRange(hsv,Scalar(0,138,200),Scalar(47,255,255),binary);	//orange
	imshow("orange",binary);
	 Mat canny_output;
       vector<vector<Point> > contours;
       vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( binary, canny_output, thresh, thresh*5, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
 

 
std::vector<std::vector<cv::Point> > contours_poly( contours.size() );
 vector<Point2f>center( contours.size() );
    vector<float>radius( contours.size() );



    //Get the  minimum enclosing circles for the updated contours
    for( int i = 0; i < contours.size(); i++ )
     { 

        approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
        minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );

     }
	float max=0;
	int count=0;
	for(int i=0;i<contours.size();i++)
	{
		if(max<radius[i])
		{max=radius[i]; count=i;}
		else max=max;
	}
	
	Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
	
	
	int a=count;
				
		circle( drawing, center[a], (int)radius[a], Scalar(0,165,255), 2, 8, 0 );
		printf(" %.2f  %.2f %.2f \n", center[a].x, center[a].y,radius[a]) ;
	
	imshow("drawing",drawing);
        inRange(hsv,Scalar(40,100,100),Scalar(90,255,255),binary2);	//green
	imshow("green",binary2);
	 Mat canny_output1;
       vector<vector<Point> > contours1;
       vector<Vec4i> hierarchy1;

  /// Detect edges using canny
  Canny( binary2, canny_output1, thresh, thresh*5, 3 );
  /// Find contours
  findContours( canny_output1, contours1, hierarchy1, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
 

 
std::vector<std::vector<cv::Point> > contours_poly1( contours1.size() );
 vector<Point2f>center1( contours.size() );
    vector<float>radius1( contours.size() );



    //Get the bounding rectangles, minimum enclosing circles for the updated contours
    for( int i = 0; i < contours1.size(); i++ )
     { 

        approxPolyDP( Mat(contours1[i]), contours_poly1[i], 3, true );
        minEnclosingCircle( (Mat)contours_poly1[i], center1[i], radius1[i] );

     }
	 max=0;
	count=0;
	for(int i=0;i<contours1.size();i++)
	{
		if(max<radius1[i])
		{max=radius1[i]; count=i;}
		else max=max;
	}
	
	Mat drawing1 = Mat::zeros( canny_output1.size(), CV_8UC3 );
	
	
	 a=count;
				
		circle( drawing1, center1[a], (int)radius1[a], Scalar(0,255,0), 2, 8, 0 );
		printf(" %.2f  %.2f %.2f \n", center1[a].x, center1[a].y,radius1[a]) ;
	
	imshow("drawing1",drawing1);
	combine=drawing | drawing1;
	imshow("combine",combine);

 int k = waitKey(33);
        if ( k==27 )
            break;
}
}


	
	
		
	

