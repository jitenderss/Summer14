/* this code will detect two colors red and yellow{ u can change to extract more colors ,just enter the values of hsv}, and then find the distance between the rectangular strips center and also the angular displacement
	inRange(hsv, Scalar(20,100, 100), Scalar(30,255, 255), binary);	yellow
	inRange(hsv, Scalar(157,72, 156), Scalar(180,169, 255), binary);	pink
	inRange(hsv, Scalar(30,50, 50), Scalar(70,255, 255), binary);		green
	inRange(hsv, Scalar(40,0, 180), Scalar(135,110, 255), binary);       white
      	inRange(hsv, Scalar(200,0, 0), Scalar(210,255, 255), binary);		purple
	inRange(hsv, Scalar(40, 44, 101), Scalar(99, 255, 255), binary2);    yellow
	there is a code in /hsv/hsvplot  which can decide range of hsv for any colour in any kind of lightning condition for thresholding
*/





#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace cv;
using namespace std;


Mat src; Mat combine,src_gray,hsv,binary,binary2,dilated,dilated2;
int thresh = 40;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );
void thresh_callback1(int, void* );
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
    inRange(hsv, Scalar(157, 72, 156), Scalar(180, 169, 255), binary);  //pink detection
	inRange(hsv, Scalar(40, 44, 101), Scalar(99, 255, 255), binary2);//yellow detection
     
/*
cvtColor( image,combine, CV_GRAY2BGR );
imshow("combine",image);*/


    imshow("binary",binary);
 imshow("binary2",binary2);
cv::Mat elements(7,7,CV_8U,cv::Scalar(1));
         cv::dilate(binary,dilated,elements);		// making more clear the image
	imshow("dilated",dilated);
cv::Mat element(7,7,CV_8U,cv::Scalar(1));
         cv::dilate(binary2,dilated2,element);
imshow("dilated2",dilated2);


  imshow( "input", src );

  thresh_callback( 0, 0 );			//for pink rectangle detection(calling function)
  thresh_callback1( 0, 0 );			//for yellow rectangle detection(calling function)

/*image=drawing | drawing2;
imshow("final",image);*/
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
  Canny( dilated, canny_output, thresh, thresh*5, 3 );
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
     int z=maxarea(area,contours.size());		// there may be little pink color somwhere due to noise,so select max area strip
	Point2f rect_points[4]; minRect[z].points( rect_points );
	for(int j=0;j<4;j++)
	{
		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
	 	line( drawing, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );
	}
	
	printf("x=%f, y=%f \n",minRect[z].center.x ,minRect[z].center.y);
	printf("angle =%f\n",minRect[z].angle);
       imshow( "drawing", drawing );
}
void thresh_callback1(int, void* )
{
  Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( dilated2, canny_output, thresh, thresh*5, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
 


  Mat drawing2 = Mat::zeros( canny_output.size(), CV_8UC3 );
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
	 	line( drawing2, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );
	}
	
	printf("x=%f, y=%f \n",minRect[z].center.x ,minRect[z].center.y);
	printf("angle =%f\n",minRect[z].angle);
       imshow( "drawing2", drawing2 );
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








