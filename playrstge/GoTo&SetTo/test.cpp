
/* g++ -o test `pkg-config --cflags playerc++`test.cpp `pkg-config --libs playerc++`  -I/usr/local/include/player-2.1 -L/usr/lib*/ //command for compiling the program
 

#include <iostream>
#include <libplayerc++/playerc++.h>
double w,v,x,y;
double speed,turnrate;
int main(int argc, char *argv[])
{
  using namespace PlayerCc;

  PlayerClient robot("localhost",6665);
  Position2dProxy pp(&robot,0);
  pp.SetMotorEnable(true);
  PlayerClient robot2("localhost",6666);
  Position2dProxy pp2(&robot2,0);
  pp2.SetMotorEnable(true);
 //pp.GoTo(3.0,0.0,dtor(0));
   // pp.GoTo((player_pose2d_t){10.0, 10.0, 5.0}, (player_pose2d_t){100.0, 0.0, 100.0});
  for(;;)
  {
    double turnrate, speed;


    // read from the proxies
    robot.Read();
    //robot2.Read();

  /*  w=pp2.GetYawSpeed();//fetching the turnrate
    x=pp2.GetXPos();//fetching xposition
    y=pp2.GetYPos();//fetching y position
    turnrate = dtor(10);//rotational velocity
    speed = 0.400; // translational velocity
    printf(" x %lf \t y %lf \t w %lf \t v %lf \n",x,y,w,v);
    pp2.GoTo(5.0,0.0,0.0);
    // command the motors
     pp2.SetSpeed(2.0, 0.0);
    pp2.SetSpeed(2.0, 2.0);*/
    pp.SetSpeed(1.0,6.0);
   // pp.SetSpeed(1.0,0.0);
    
  }
}
