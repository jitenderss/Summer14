#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int main()
{
    VideoCapture cap(1);     // get 'any' cam
    while( cap.isOpened() )   // check if we succeeded
    {
        Mat frame,src_gray,hsv,binary;
        if ( ! cap.read(frame) )
            break;
       cvtColor( frame, hsv, CV_BGR2HSV );
	//inRange(hsv, Scalar(20,100, 100), Scalar(30,255, 255), binary);	/*yellow*/
	//inRange(hsv, Scalar(157,72, 156), Scalar(180,169, 255), binary);	/*pink*/
	inRange(hsv, Scalar(30,50, 50), Scalar(70,255, 255), binary);		/*green*/
	//inRange(hsv, Scalar(40,0, 180), Scalar(135,110, 255), binary);       /*white*/
      	//inRange(hsv, Scalar(200,0, 0), Scalar(210,255, 255), binary);		/*purple*/
	 imshow("lalala",binary);
	imshow("original",frame);
        int k = waitKey(33);
        if ( k==27 )
            break;
    }
    return 0;
}
