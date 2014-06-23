#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace cv;
using namespace std;


Mat src; Mat combine,src_gray,hsv,binary,binary2,dilated,dilated2;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );
int maxarea(float a[],int b);


/** @function main */
int main( int argc, char** argv )
{
  /// Load source image and convert it to gray
  src = imread( argv[1], 1 );

  Mat image;
	image.create(src.size(),src.type());
	 
cvtColor(src, hsv, CV_BGR2HSV);
	/*imshow("HSV",hsv);*/
    inRange(hsv, Scalar(157, 72, 156), Scalar(180, 169, 255), binary);
	inRange(hsv, Scalar(20, 100, 100), Scalar(30, 255, 255), binary2);
     
image=binary | binary2;
/*cvtColor( image,combine, CV_GRAY2BGR );
imshow("combine",image);*/


    imshow("binary",binary);
 imshow("binary2",binary2);
cv::Mat elements(7,7,CV_8U,cv::Scalar(1));
         cv::dilate(image,dilated,elements);
	imshow("dilated",dilated);

 char* source_window = "Source";
  namedWindow( source_window, CV_WINDOW_AUTOSIZE );
  imshow( source_window, src );
  createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
  thresh_callback( 0, 0 );

  waitKey(0);
  return(0);
}

/** @function thresh_callback */
void thresh_callback(int, void* )
{
  Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( dilated, canny_output, thresh, thresh*2, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
 


  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
vector<RotatedRect> minRect( contours.size() );
for( int i = 0; i < contours.size(); i++ )
    { 
       minRect[i] = minAreaRect( Mat(contours[i]) );
    } 

float area[contours.size()];
for( int i = 0; i< contours.size(); i++ )
  {
	
	Point2f rect_points[4]; minRect[i].points( rect_points );
	area[i] =  (minRect[i].size.width)*(minRect[i].size.height);	
  }
     int z=maxarea(area,contours.size());
	Point2f rect_points[4]; minRect[z].points( rect_points );
	for(int j=0;j<4;j++)
	{
		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
	 	line( drawing, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );
	}
	
	printf("x=%f, y=%f \n",minRect[z].center.x ,minRect[z].center.y);
	printf("angle =%f\n",minRect[z].angle);
       imshow( "drawing", drawing );


 /* /// Get the moments
  vector<Moments> mu(contours.size() );
  for( int i = 0; i < contours.size(); i++ )
     { mu[i] = moments( contours[i], false ); }

  ///  Get the mass centers:
  vector<Point2f> mc( contours.size() );
  for( int i = 0; i < contours.size(); i++ )
     { mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }

  /// Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       if((mu[i].m00)!=0)
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
       /*circle( drawing, mc[i], 4, color, -1, 8, 0 );*/
     

  /*/// Show in a window
  namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );

  /// Calculate the area with the moments 00 and compare with the result of the OpenCV function
  printf("\t Info: Area and Contour Length \n");
  for( int i = 0; i< contours.size(); i++ )
     {
	if((mu[i].m00)!=0)
       printf(" * Contour[%d] - Area (M_00) = %.2f - Area OpenCV: %.2f - Length: %.2f \n", i, mu[i].m00, contourArea(contours[i]), arcLength( contours[i], true ) );
       /*Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
       circle( drawing, mc[i], 4, color, -1, 8, 0 );*/
     
  /*for( int i = 0; i < contours.size(); i++ )
    {
	/*if(contourArea(contours[i])>50)*/
	/*printf(" contour[%d] - centroid x =%f \n ",i,mc[i].x);
        printf(" contour[%d] - centroid y = %f \n ",i,mc[i].y);      
	}
   printf("no of countours = %d",contours.size());*/
}
int maxarea(float a[],int b)
{
	int max=0,c;
	for(int i=0;i<b;i++)
	{
		if(a[i]>max)
		{max=a[i];c=i;}
		else max=max;
	}
	return c;
}








