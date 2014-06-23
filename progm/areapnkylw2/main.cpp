#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src; Mat src_gray,hsv,binary,dilated;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );

/** @function main */
int main( int argc, char** argv )
{
  src = imread( argv[1], 1 );


   
cvtColor(src, hsv, CV_BGR2HSV);
	/*imshow("HSV",hsv);*/
    //inRange(hsv, Scalar(157, 72, 156), Scalar(180, 169, 255), binary);
inRange(hsv, Scalar(110,100, 109), Scalar(138, 255, 255), binary);    
imshow("binary",binary);
cv::Mat elements(7,7,CV_8U,cv::Scalar(1));
         cv::dilate(binary,dilated,elements);
	imshow("dilated",dilated);



 
  
  

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


for( int i = 0; i< contours.size(); i++ )
  {
	Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
	Point2f rect_points[4]; minRect[i].points( rect_points );
       for( int j = 0; j < 4; j++ )
         { line( drawing, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );}
	printf("x=%f, y=%f \n",minRect[i].center.x ,minRect[i].center.y);
	printf("angle =%f\n",minRect[i].angle);
	printf("points=%f,%f\n",rect_points[3].x,rect_points[3].y);
	if(i== contours.size()-1)
	{
		/*if(dilated.at<Vec3b>(320,200)[0] == 0 && dilated.at<Vec3b>(320,200)[1] == 0 && dilated.at<Vec3b>(320,200)[2] == 0)
		printf("yes\n");*/
		printf("b%d\n",dilated.at<Vec3b>(285,200)[0]);
	}
	
}
    imshow( "draw", drawing );
 



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


