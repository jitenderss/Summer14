
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
  
  double w,vx1,vx2,vy1,vy2,y,h;
  double x1=0.0,y1=0.0,x2,y2,x3,y3;
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
 // pp.SetSpeed(0.0,dtor(900));
 // pp2.SetSpeed(0.0,dtor(900));
  double speed=1.0;
  double speed2=1.0;
  double speed3=1.0;
  int flag =0;
  
  for(;;)
  {
	
	robot.Read();
	robot2.Read(); 
    	robot3.Read();
	pp.SetSpeed(1.0,dtor(0));
	x1=pp.GetXPos();//fetching xposition
    	y1=pp.GetYPos();//fetching y position
    	x2=pp2.GetXPos();
    	y2=pp2.GetYPos();
	x3=pp3.GetXPos();
    	y3=pp3.GetYPos();
	w=pp2.GetYaw();
	h=pp3.GetYaw();
	double r=abs(y2-y1);
	double s=abs(x2-x1);
	double t=abs(y3-y1);
	double u=abs(x3-x1);
	cout<<s<<" "<<r<<" "<<u<<" "<<t<<" "<<w<<endl;
	if(s>=1.05 && r>=0.9 && r<=1.1)
	{
	        speed2=speed2+(speed2/10);
		if(speed2<=1.5)
		pp2.SetSpeed(speed2,(-10)*w);
		else
		{
			speed2=speed2-(speed2/10);
			pp2.SetSpeed(1.5,(-10)*w);
			
		}
		flag=1;
		//cout<< pp2.GetXSpeed()<<"first ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s>=1.05 && r>=1.1 )
	{
		
	        speed2=speed2+(speed2/10);
		if(speed2<=1.5)
		pp2.SetSpeed(speed2,dtor(10));
		else
		{
			speed2=speed2-(speed2/10);
			pp2.SetSpeed(1.5,dtor(10));
			
		}
		flag=1;
		//cout<< pp2.GetXSpeed()<<"second ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s>=1.05 && r<=0.9 )
	{
		
	        speed2=speed2+(speed2/10);
		if(speed2<=1.5)
		pp2.SetSpeed(speed2,dtor((-1)*10));
		else
		{
			speed2=speed2-(speed2/10);
			pp2.SetSpeed(1.5,dtor((-1)*10));
			
		}
		flag=1;
		//cout<< pp2.GetXSpeed()<<"third ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s>=0.95 && s<=1.05 && r>=0.9 && r<=1.1)
	{
	       
		pp2.SetSpeed(1.0,(-10)*w);
		flag=1;
		//cout<< pp2.GetXSpeed()<<"fourth ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s<=0.95 && r>=0.9 && r<=1.1)
	{
	        speed2=speed2-(speed2/10);
		if(speed2<=1.5)
		pp2.SetSpeed(speed2,(-10)*w);
		else
		{	
			speed2=speed2-(speed2/10);	
			pp2.SetSpeed(0.5,(-10)*w);
			
		}		
			flag=1;
		//cout<< pp2.GetXSpeed()<<"fifth ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s<=0.95 && r>=1.1 )
	{
	        speed2=speed2-(speed2/10);
		if(speed2<=1.5)
		pp2.SetSpeed(speed2,dtor(10));
		else
		{	
			speed2=speed2-(speed2/10);	
			pp2.SetSpeed(0.5,dtor(10));
			
		}		
			flag=1;
		//cout<< pp2.GetXSpeed()<<"sixth ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s<=0.95 && r<=0.9 )
	{
	        speed2=speed2-(speed2/10);
		if(speed2<=1.5)
		pp2.SetSpeed(speed2,dtor((-1)*10));
		else
		{	
			speed2=speed2-(speed2/10);	
			pp2.SetSpeed(0.5,dtor((-1)*10));
			
		}		
			flag=1;
		//cout<< pp2.GetXSpeed()<<"seventh ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s>=0.95 && s<=1.05 && r>=1.1)
	{
		speed2=1.0;
		pp2.SetSpeed(speed2,dtor(10));
		//cout<< pp2.GetXSpeed()<<"eight ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
	if(s>=0.95 && s<=1.05 && r<=0.9)
	{
		speed2=1.0;
		pp2.SetSpeed(speed2,dtor((-1)*10));
		//cout<< pp2.GetXSpeed()<<"ninth ";
		//cout<< pp2.GetYSpeed()<<" ";
	}
    	if(u>=1.05 && t>=0.9 && t<=1.1)
	{
	        speed3=speed3+(speed3/10);
		if(speed3<=1.5)
		pp3.SetSpeed(speed3,(-10)*h);
		else
		{
			speed3=speed3-(speed3/10);
			pp3.SetSpeed(1.5,(-10)*h);
			
		}
		flag=1;
		cout<< pp3.GetXSpeed()<<"first ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u>=1.05 && t>=1.1 )
	{
		
	        speed3=speed3+(speed3/10);
		if(speed3<=1.5)
		pp3.SetSpeed(speed3,dtor((-1)*10));
		else
		{
			speed3=speed3-(speed3/10);
			pp3.SetSpeed(1.5,dtor((-1)*10));
			
		}
		flag=1;
		cout<< pp3.GetXSpeed()<<"second ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u>=1.05 && t<=0.9 )
	{
		
	        speed3=speed3+(speed3/10);
		if(speed3<=1.5)
		pp3.SetSpeed(speed3,dtor(10));
		else
		{
			speed3=speed3-(speed3/10);
			pp3.SetSpeed(1.5,dtor(10));
			
		}
		flag=1;
		cout<< pp3.GetXSpeed()<<"third ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u>=0.95 && u<=1.05 && t>=0.9 && t<=1.1)
	{
	       
		pp3.SetSpeed(1.0,(-10)*h);
		flag=1;
		cout<< pp3.GetXSpeed()<<"fourth ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u<=0.95 && t>=0.9 && t<=1.1)
	{
	        speed3=speed3-(speed3/10);
		if(speed3<=1.5)
		pp3.SetSpeed(speed3,(-10)*h);
		else
		{	
			speed3=speed3-(speed3/10);	
			pp3.SetSpeed(0.5,(-10)*h);
			
		}		
			flag=1;
		cout<< pp3.GetXSpeed()<<"fifth ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u<=0.95 && t>=1.1 )
	{
	        speed3=speed3-(speed3/10);
		if(speed3<=1.5)
		pp3.SetSpeed(speed3,dtor((-1)*10));
		else
		{	
			speed3=speed3-(speed3/10);	
			pp3.SetSpeed(0.5,dtor((-1)*10));
			
		}		
			flag=1;
		cout<< pp3.GetXSpeed()<<"sixth ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u<=0.95 && t<=0.9 )
	{
	        speed3=speed3-(speed3/10);
		if(speed3<=1.5)
		pp3.SetSpeed(speed3,dtor(10));
		else
		{	
			speed3=speed3-(speed3/10);	
			pp3.SetSpeed(0.5,dtor(10));
			
		}		
			flag=1;
		cout<< pp3.GetXSpeed()<<"seventh ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u>=0.95 && u<=1.05 && t>=1.1)
	{
		speed3=1.0;
		pp3.SetSpeed(speed3,dtor((-1)*10));
		cout<< pp3.GetXSpeed()<<"eight ";
		cout<< pp3.GetYSpeed()<<" ";
	}
	if(u>=0.95 && u<=1.05 && t<=0.9)
	{
		speed3=1.0;
		pp3.SetSpeed(speed3,dtor(10));
		cout<< pp3.GetXSpeed()<<"ninth ";
		cout<< pp3.GetYSpeed()<<" ";
	}
        //pp3.SetSpeed(1.0,dtor(10));
  }
}












