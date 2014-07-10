//gcc -o test `pkg-config --cflags playerc++`test.cc `pkg-config --libs playerc++`  -I/usr/local/include/player-2.1 -L/usr/lib
#include <libplayerc++/playerc++.h>
#include <iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<csignal>
using namespace std;
//#include "args.h"
int main(int argc, char **argv)
{
  double xPos, yPos, angle;
  double xVel, yVel, aVel;
  double ypre=0,xpre=0,net_angle=0,cal_angle;
  // we throw exceptions on creation if we fail
  try
  {
    using namespace PlayerCc;

    PlayerClient robot ("172.26.94.18");
    Position2dProxy pp (&robot);
	CameraProxy camera(&robot, 0);
    std::cout << robot << std::endl;

    pp.SetMotorEnable (true);

    // go into read-think-act loop
    double newspeed = 0.1, newturnrate =dtor(0);
    for(;;)
    {

		/* this blocks until new data comes; 10Hz by default */
		robot.Read();

		// write commands to robot
		pp.SetSpeed(newspeed,newturnrate);
		xPos = pp.GetXPos();
		yPos = pp.GetYPos();
		angle = pp.GetYaw();
		xVel = pp.GetXSpeed();
		yVel = pp.GetYSpeed();
		aVel = pp.GetYawSpeed();
		if ((xPos==0) && (yPos==0)) 
		{
			cal_angle=0;
					}
		else
		{
		cal_angle=atan2((yPos-ypre),(xPos-xpre));
			}
       xpre=xPos;
       ypre=yPos; 
		if (camera.GetCompression()) {
		cout << "Image compressed. " << endl;
		camera.Decompress(); // Decompress the image (if we conpressed it in the player config file)
	}
	cout << "Image width: " << camera.GetWidth() << endl;
	cout << "Image height: " << camera.GetWidth() << endl;
	cout << "Image depth: " << camera.GetDepth() << endl;
	// The image date can be coppied to some already alocated memory
	// eg.
	unsigned char *imagedata = new unsigned char[camera.GetImageSize()];
	camera.GetImage(imagedata);
	// Now write the image to file or use the data some how
	// The format of the data is RGBRGBRGBRGBRGB row major
	FILE *file = fopen("testimage.ppm","w");
	fprintf(file, "P6\n%d %d\n255\n",camera.GetWidth(),camera.GetHeight());
	fwrite(imagedata,camera.GetImageSize(),1,file);
	fclose(file);
	delete imagedata;   
		printf("X = %f, Y = %f, angle = %f, xVel = %f, yVel = %f, cal_angle = %f , angular speed =%lf\n", xPos, yPos,angle, xVel, yVel, cal_angle, aVel);

    }
  }
  catch (PlayerCc::PlayerError & e)
  {
    std::cerr << e << std::endl;
    return -1;
  }
}
