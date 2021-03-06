
/* g++ -o test `pkg-config --cflags playerc++`test.cpp `pkg-config --libs playerc++`  -I/usr/local/include/player-2.1 -L/usr/lib*/ //command for compiling the program
 

#include <iostream>
#include <libplayerc++/playerc++.h>
#include <aruco/aruco.h>
#include <aruco/cvdrawingutils.h>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include<cv.h>
#include<highgui.h>
double w,v,x,y;
double speed,turnrate;
int
main(int argc, char *argv[])
{
  using namespace PlayerCc;
  using namespace cv;
  using namespace aruco;
  PlayerClient robot("localhost",6665);
  Position2dProxy pp(&robot,0);
  pp.SetMotorEnable(true);
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
            Markers[i].draw(InImage,cv::Scalar(0,0,255),2);
        }/* if(argc !=2)
    {
     cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image,color_dst;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR); 
    cvtColor( image, color_dst, CV_BGR2GRAY );
    imwrite( "../Gray_Image.jpg", color_dst);

    if(! image.data)
    {
      cout << "Could not open or find the image"<< endl;
      return -1;
    }
    
    namedWindow("Display window", CV_WINDOW_AUTOSIZE);
    imshow("Display Window",color_dst);*/
    
   // waitKey(0);
        cv::imshow("in",InImage);
        cv::waitKey(0);//wait for key to be pressed
  for(;;)
  {
    double turnrate, speed;

    // read from the proxies
    robot.Read();

    w=pp.GetYawSpeed();//fetching the turnrate
    x=pp.GetXPos();//fetching xposition
    y=pp.GetYPos();//fetching y position
    turnrate = dtor(10);//rotational velocity
    speed = 0.400; // translational velocity
    printf(" x %lf \t y %lf \t w %lf \t v %lf \n",x,y,w,v);
    // command the motors
    pp.SetSpeed(speed, turnrate);
  }
}
