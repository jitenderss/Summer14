#include <iostream>
#include <aruco/aruco.h>
#include <aruco/cvdrawingutils.h>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>


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
	Point2f up[Markers.size()];
	for(int i=0;i<Markers.size();i++)
	{
		up[i].x=(Markers[i][0].x+Markers[i][1].x)/2;
		up[i].y=(Markers[i][0].y+Markers[i][1].y)/2;
		cout<< up[i].x<<","<<up[i].y<<endl;
	}
	int ref=0;
	cout<<center[ref].x<<","<<center[ref].y<<endl;
	cout<<up[ref].x<<","<<up[ref].y<<endl;
	double r=(center[ref].y-up[ref].y);
	double s=(center[ref].x-up[ref].x);
	double angle = atan2(abs(r),abs(s)) * 180.0 / CV_PI;
	cout<< angle<<" "<<-angle;
	cout << cos(angle*CV_PI/180.0)<<sin((180.0-angle)*CV_PI/180.0)<<endl;
	
	double t[3][3]={1,0,-(center[ref].x),0,1,-(center[ref].y),0,0,1};
	/*for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<t[i][j];
			
		}
	}*/
	double rot[3][3];
	rot[0][2]=0;rot[1][2]=0;rot[2][0]=0;rot[2][1]=0;rot[2][2]=1;
	if(r>0 && s>0)
	{
		rot[0][0]=rot[1][1]=cos((180.0-angle)*CV_PI/180.0);
		rot[1][0]=sin((180.0-angle)*CV_PI/180.0);
		rot[0][1]=(-1)*(rot[1][0]);
	}
	if(r<0 && s<0)
	{
		rot[0][0]=rot[1][1]=cos((-angle)*CV_PI/180.0);
		rot[1][0]=sin((-angle)*CV_PI/180.0);
		rot[0][1]=(-1)*(rot[1][0]);
	}
	if(r>0 && s<0)
	{
		rot[0][0]=rot[1][1]=cos((angle)*CV_PI/180.0);
		rot[1][0]=sin((angle)*CV_PI/180.0);
		rot[0][1]=(-1)*(rot[1][0]);
	}
	if(r<0 && s>0)
	{
		rot[0][0]=rot[1][1]=cos((angle-180.0)*CV_PI/180.0);
		rot[1][0]=sin((angle-180.0)*CV_PI/180.0);
		rot[0][1]=(-1)*(rot[1][0]);
	}
	/*for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<rot[i][j]<<" ";
			
		}
	}*/
	double multp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
	        	multp[i][j]=0;
        		for(int k=0;k<3;k++)
			{
				multp[i][j]=multp[i][j]+(rot[i][k] * t[k][j]);
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<multp[i][j]<<" ";
			
		}
	}
	
	double conv[3][1];
	for(int j=0;j<3;j++)
	{
	    cin>>conv[j][0];
	}
	double transf[3][1];
	for(int i=0;i<3;i++)
	{
		        transf[i][0]=0;
		        for(int k=0;k<3;k++)
			{
				transf[i][0]=transf[i][0]+(multp[i][k] * conv[k][0]);
			}
		
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<1;j++)
		{
			cout<<transf[i][j]<<" ";
			
		}
	}
		
	




        cv::imshow("in",InImage);
        cv::waitKey(0);//wait for key to be pressed
    } catch (std::exception &ex)
    {
        cout<<"Exception :"<<ex.what()<<endl;
    }

    return 0;
}
 
