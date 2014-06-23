
/* g++ -o test `pkg-config --cflags playerc++`test.cpp `pkg-config --libs playerc++`  -I/usr/local/include/player-2.1 -L/usr/lib*/ //command for compiling the program
 

#include <iostream>
#include <libplayerc++/playerc++.h>
#include<math.h>
#include<stdio.h>

using namespace std;
double speed,turnrate;
int
main(int argc, char *argv[])
{
  int count=0;
  
  double w,vx1,vx2,vy1,vy2;
  double x1=0.0,y1=0.0,x2,y2;
  double angle,prevangle=0,newangle;
  using namespace PlayerCc;
  PlayerClient robot("localhost",6665);
  PlayerClient robot2("localhost",6666);
  PlayerClient robot3("localhost",6667);
  Position2dProxy pp(&robot,0);
  Position2dProxy pp2(&robot2,0);
  Position2dProxy pp3(&robot3,0);
  pp.SetMotorEnable(true);
  pp2.SetMotorEnable(true);
  pp3.SetMotorEnable(true);
  for(;;)
  {
	robot.Read();
	robot2.Read(); 
    	robot3.Read();
	pp.SetSpeed(1.0,dtor(450));
    	pp2.SetSpeed(1.0,dtor(450));
        pp3.SetSpeed(1.0,dtor(450));
  }
}



