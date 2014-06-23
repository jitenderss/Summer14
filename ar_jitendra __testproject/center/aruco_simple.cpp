#include <iostream>
#include <aruco/aruco.h>
#include <aruco/cvdrawingutils.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace aruco;

int main(int argc,char **argv)
{
    try
    {
        if (argc!=2) {
            cerr<<"Usage: in.jpg "<<endl;
            return -1;
        }
        MarkerDetector MDetector;
        vector<Marker> Markers;
        //read the input image
        cv::Mat InImage;
        InImage=cv::imread(argv[1]);
    //Ok, let's detect
        MDetector.detect(InImage,Markers);
        //for each marker, draw info and its boundaries in the image
        for (unsigned int i=0;i<Markers.size();i++) {
            cout<<Markers[i]<<endl;
		cout<<Markers[0][0].x<<endl;
            Markers[i].draw(InImage,Scalar(0,0,255),2);
        }
	Point2f center[Markers.size()];
	for(int i=0;i<Markers.size();i++)
	{
		float a= (Markers[i][0].x+Markers[i][1].x+Markers[i][2].x+Markers[i][3].x)/4;
		float b= (Markers[i][0].y+Markers[i][1].y+Markers[i][2].y+Markers[i][3].y)/4;
		center[i].x= a;
		center[i].y= b;
		cout<<a<<","<<b<<endl;
	}
	/*Point2f up[Markers.size()];
	for(int i=0;i<Markers.size();i++)
	{
		up[i].x=(Markers[i][0].x+Markers[i][1].x)/2;
		up[i].y=(Markers[i][0].y+Markers[i][1].y)/2;
		cout<< up[i].x<<","<<up[i].y<<endl;
	}*/




        cv::imshow("in",InImage);
        cv::waitKey(0);//wait for key to be pressed
    } catch (std::exception &ex)
    {
        cout<<"Exception :"<<ex.what()<<endl;
    }

    return 0;
}
 
