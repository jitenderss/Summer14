
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
  Position2dProxy pp(&robot,0);
  Position2dProxy pp2(&robot2,0);
  pp.SetMotorEnable(true);
  pp2.SetMotorEnable(true);
  // pp.SetSpeed(3.0, dtor(45));
  for(;;)
  {
    double a,b;
   
    // read from the proxies
    robot.Read();
    robot2.Read();
    // w=pp.GetYawSpeed();//fetching the turnrate
    x1=pp.GetXPos();//fetching xposition
    y1=pp.GetYPos();//fetching y position
    x2=pp2.GetXPos();
    y2=pp2.GetYPos();
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    a=x1;b=y1;
	double r=abs(y2-y1);
	double s=abs(x2-x1);
	double u=abs(y2-b);
	double v=abs(x2-a);
	
		 angle = (atan2(r,s)*180)/3.14159 ; 
		cout<<angle<<endl;
	
 if(count==0)
{	if(x2>x1&&y2>y1)
	{	
		newangle=1800+10*angle;
		pp2.SetSpeed(0.0,0.0,dtor(newangle-prevangle));
		prevangle=newangle;
	}
	if(x2>x1 && y2<y1)
	{
		newangle=1800-10*angle;
		pp2.SetSpeed(0.0,0.0,dtor(newangle-prevangle));
		prevangle=newangle;
	}
	if(x2<x1 && y2>y1)
	{
		newangle=-1*10*angle;
		pp2.SetSpeed(0.0,0.0,dtor(newangle-prevangle));
		prevangle=newangle;
	}
	if(x2<x1 && y2<y1)
	{
		newangle=10*angle;
		pp2.SetSpeed(0.0,0.0,dtor(newangle-prevangle));
		prevangle=newangle;
	}
	count=1;
}	
		
   
   else
	{	 pp2.SetSpeed(3.0,0);
		count=0;
	}
	
    pp.SetSpeed(1,dtor(45));
    //double r= sqrt((x2-x1)^2 + (y2-y1)^2);
    
    
  }
}
