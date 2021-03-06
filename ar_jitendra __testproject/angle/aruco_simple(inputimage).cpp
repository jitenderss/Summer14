/* this program calculates distance between robot's com with respect to refrence robot and also the angular displacement*/
// press escape for exit 
/* cd build
	cmake ..
	make
	./aruco_simple ../name.jpg
*/




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
		//cout<<Markers[0][0].x<<endl;
            Markers[i].draw(InImage,Scalar(0,0,255),2);
        }
	Point2f center[Markers.size()];
	for(int i=0;i<Markers.size();i++)        //calculating the center points of each detected markers
	{
		float a= (Markers[i][0].x+Markers[i][1].x+Markers[i][2].x+Markers[i][3].x)/4;
		float b= (Markers[i][0].y+Markers[i][1].y+Markers[i][2].y+Markers[i][3].y)/4;
		center[i].x= a;
		center[i].y= b;
		//cout<<a<<","<<b<<endl;
	}
	Point2f up[Markers.size()];  //calculating upper head point which is the midpoint of red and green to give direction to each one
	for(int i=0;i<Markers.size();i++)
	{
		up[i].x=(Markers[i][0].x+Markers[i][1].x)/2;   //Markers[i][0] for red and Markers[i][1] for green
		up[i].y=(Markers[i][0].y+Markers[i][1].y)/2;
		//cout<< up[i].x<<","<<up[i].y<<endl;
	}
	int ref;
	cin>>ref;
	cout<<"center of ref "<<center[ref].x<<","<<center[ref].y<<endl;
	cout<<"up of ref "<<up[ref].x<<","<<up[ref].y<<endl;
	double r=(center[ref].y-up[ref].y);
	double s=(center[ref].x-up[ref].x);
	double angle = atan2(abs(r),abs(s)) * 180.0 / CV_PI;
	cout<<"angle of ref is "<< angle<<endl;
	cout <<"cosine of angle of ref is "<< cos(angle*CV_PI/180.0)<<"and sin is "<<sin((180.0-angle)*CV_PI/180.0)<<endl;
	
	double t[3][3]={1,0,-(center[ref].x),0,1,-(center[ref].y),0,0,1};  // translation matrix to convert points into the frame of reference robot
	/*for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<t[i][j];
			
		}
	}*/
	double rot[3][3];			// calculating rotation matrix
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
	double multp[3][3];  // overall transformation matrix
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
	/*for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<multp[i][j]<<" ";
			
		}
	}*/
	Point2f cntr[Markers.size()];
	for(int m=0;m<Markers.size();m++)
	{	
		double conv[3][1];		// stores the center point which needed to be converted into ref frame
		for(int j=0;j<3;j++)
		{
			conv[2][0]=1;
			conv[0][0]=center[m].x;
			conv[1][0]=center[m].y;
			
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
			cntr[m].x=transf[0][0];			// new center coordinates of each marker with respect to reference marker
			cntr[m].y=transf[1][0];
		/*for(int i=0;i<3;i++)
		{
			for(int j=0;j<1;j++)
			{
				cout<<transf[i][j]<<" ";
				
			}
		}*/
		cout<<"relative center of  "<< m <<"is"<<cntr[m].x<<","<<cntr[m].y<<"& in realtime"<<0.315*cntr[m].x<<","<<0.315*cntr[m].y<<endl;		
	}
	Point2f top[Markers.size()];  // similarly convert each top points of marker into another frame 
	for(int m=0;m<Markers.size();m++)
	{	
		double conv[3][1];
		for(int j=0;j<3;j++)
		{
			conv[2][0]=1;
			conv[0][0]=up[m].x;
			conv[1][0]=up[m].y;
			
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
			top[m].x=transf[0][0];
			top[m].y=transf[1][0];
		
		cout<<"relative top cord of "<<m<<"is "<<top[m].x<<","<<top[m].y<<endl;		
	}	
	double rotangl[Markers.size()];     //calculating angle by which reference marker should be rotated to get the other marker orientation
	for(int m=0;m<Markers.size();m++)
	{
		double u=cntr[m].y-top[m].y;
		double v=cntr[m].x-top[m].x;
		double theta=atan2(abs(u),abs(v)) * 180.0 / CV_PI;
		if(v<0 && u>0)
		{
			rotangl[m]=theta;
		}
		if(v>0 && u>0)
		{
			rotangl[m]=(180.0 - theta);
		}
		if(u<0 && v>0)
		{
			rotangl[m]=theta-180;
		}
		if(u<0 && v<0)
		{
			rotangl[m]=(-1)*theta;
		}
		cout<<"angle to rotate to get "<<m<<"th marker is"<<rotangl[m]<<endl;
	}
		
	
        cv::imshow("in",InImage);
        cv::waitKey(0);//wait for key to be pressed
    } catch (std::exception &ex)
    {
        cout<<"Exception :"<<ex.what()<<endl;
    }

    return 0;
}
 
