/* g++ -o test `pkg-config --cflags playerc++`test.cpp `pkg-config --libs playerc++`  -I/usr/local/include/player-2.1 -L/usr/lib*/ //command for compiling the program


#include <iostream>
#include <libplayerc++/playerc++.h>
#include <stdio.h>
using namespace std; 
int
main(int argc, char *argv[])
{
  using namespace PlayerCc;
  

  PlayerClient    robot("localhost",6665);
  SonarProxy      sp(&robot,0);
  Position2dProxy pp(&robot,0);
   PlayerClient    robot2("localhost",6666);
  SonarProxy      sp2(&robot2,0);
  Position2dProxy pp2(&robot2,0);


  for(;;)
  {
    double turnrate, speed,turnrate2, speed2;

    // read from the proxies
    robot.Read();
    robot2.Read();
    // print out sonars for fun
    //std::cout << sp << std::endl;

    // do simple collision avoidance
    if((sp[0] + sp[1]) < (sp[6] + sp[7]))
      {turnrate = dtor(-90); // turn 20 degrees per second
	cout<<"hat be"<<endl;}
    else
      turnrate = dtor(90);

    if(sp[3] < 0.500)
      speed = 0.0;
    else
      speed = 4.500;


       if((sp2[0] + sp2[1]) < (sp2[6] + sp2[7]))
      {
	turnrate2 = dtor(-90); // turn 20 degrees per second
	cout<<"bal bal bache"<<endl;
      }
    else
      turnrate2 = dtor(90);

    if(sp2[3] < 0.500)
      speed2 = 0.0;
    else
      speed2 = 4.500;

    // command the motors
    pp.SetSpeed(speed, turnrate);
  
    pp2.SetSpeed(speed2, turnrate2);

  }
}
