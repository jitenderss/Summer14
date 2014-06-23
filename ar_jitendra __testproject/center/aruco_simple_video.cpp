#include <iostream>
#include <aruco/aruco.h>
#include <aruco/cvdrawingutils.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace aruco;

int main(int argc,char **argv)
{


	MarkerDetector MDetector;
	        vector<Marker> Markers;
	VideoCapture cap(1); // open the video camera no. 0

	    if (!cap.isOpened())  // if not success, exit program
	    {
	cout << "Cannot open the video cam" << endl;
	        return -1;
	    }

	   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	    while (1)
	    {
	        Mat frame;

	        bool bSuccess = cap.read(frame); // read a new frame from video

	if (!bSuccess) //if not success, break loop
	{
	cout << "Cannot read a frame from video stream" << endl;
	break;
	}

	MDetector.detect(frame,Markers);

	for (unsigned int i=0;i<Markers.size();i++) {
	            cout<<Markers[i]<<endl;
	            Markers[i].draw(frame,Scalar(0,0,255),2);
	        }
	Point2f center[Markers.size()];
	for(int i=0;i<Markers.size();i++)
	{
		float a= (Markers[i][0].x+Markers[i][1].x+Markers[i][2].x+Markers[i][3].x)/4;
		float b= (Markers[i][0].y+Markers[i][1].y+Markers[i][2].y+Markers[i][3].y)/4;
		center[i].x= a;
		center[i].y= b;
		cout<<"tela";
		cout<<a<<","<<b<<endl;
	}


	        imshow("MyVideo", frame); //show the frame in "MyVideo" window

	        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
	{
	cout << "esc key is pressed by user" << endl;
	break;
	}
	    }
	    return 0;


}

