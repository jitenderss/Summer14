
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
  //pp3.SetMotorEnable(true);
 // pp.SetSpeed(0.0,dtor(900));
 // pp2.SetSpeed(0.0,dtor(900));
  double speed=1.0;
  double speed2=1.0;
  int flag =0;
  cout<<speed/2;
  for(;;)
  {
	
	robot.Read();
	robot2.Read(); 
    	//robot3.Read();
	pp.SetSpeed(1.0,dtor(0));
	x1=pp.GetXPos();//fetching xposition
    	y1=pp.GetYPos();//fetching y position
    	x2=pp2.GetXPos();
    	y2=pp2.GetYPos();
	double r=abs(y2-y1);
	double s=abs(x2-x1);
	cout<<x1<<" "<<x2<<" "<<s<<endl;
	if(s>1.05)
	{
	        speed2=speed2+(speed2/10);
		if(speed2<=2.5)
		pp2.SetSpeed(speed2,0);
		else
		{
			speed2=speed2-(speed2/10);
			pp2.SetSpeed(2.5,0);
			
		}
		flag=1;
		cout<< pp2.GetXSpeed()<<"door ";
		cout<< pp2.GetYSpeed()<<" ";
	}
	if(s>0.95 && s<=1.05)
	{
	        
		pp2.SetSpeed(1.0,0);
		flag=1;
		cout<< pp2.GetXSpeed()<<"yes ";
		cout<< pp2.GetYSpeed()<<" ";
	}
	if(s<=0.95)
	{
	        speed2=speed2-(speed2/10);
		if(speed2<=2.5)
		pp2.SetSpeed(speed2,0);
		else
		{	
			speed2=speed2-(speed2/10);	
			pp2.SetSpeed(0.5,0);
			
		}		
			flag=1;
		cout<< pp2.GetXSpeed()<<"paas ";
		cout<< pp2.GetYSpeed()<<" ";
	}
	
	
    	
        //pp3.SetSpeed(1.0,dtor(45));
  }
}












