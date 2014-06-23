
/* g++ -o test `pkg-config --cflags playerc++`test.cpp `pkg-config --libs playerc++`  -I/usr/local/include/player-2.1 -L/usr/lib*/ //command for compiling the program
 

#include <iostream>
#include <libplayerc++/playerc++.h>
double w,v,x,y;
double speed,turnrate;
int
main(int argc, char *argv[])
{
  using namespace PlayerCc;

  PlayerClient robot("localhost",6665);
  Position2dProxy pp(&robot,0);
  pp.SetMotorEnable(true);
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