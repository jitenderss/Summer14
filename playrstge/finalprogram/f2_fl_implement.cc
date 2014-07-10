
/*gcc -o f2_fl_implement `pkg-config --cflags playerc++`f2_fl_implement.cc `pkg-config --libs playerc++`  -I/usr/local/include/player-2.1 -L/usr/lib*/

 #include <libplayerc++/playerc++.h>
 #include <iostream>
 #include<csignal>
 #define pi 3.14159
 #define d 0.25

//double DEG2RAD(double deg)
//{
  //double rad = pi*deg/180;
  //return(rad);
//}


int main(int argc, char *argv[])
{
  using namespace PlayerCc;
  using namespace std;

  FILE *f1;
   PlayerClient r1("172.26.94.94");
   PlayerClient r2("172.26.94.95");
  //PlayerClient r1("localhost", 6665);
  //PlayerClient r2("localhost", 6666);
  //PlayerClient r3("localhost", 6667);
  Position2dProxy p1(&r1);
  p1.SetMotorEnable(true);
  Position2dProxy p2(&r2);
  p2.SetMotorEnable(true);
  //Position2dProxy p3(&r3);
  //p3.SetMotorEnable(true);

  int i,j,k;
  double xpos,ypos,theta;//pose of robot
  double vl ,vf, wl , wf,vf1,wf1;
  double xl, yl, phil; //double rhod[2], shid[2];
  double xf,yf, phif;  //double xh[2],yh[2],phih[2],xv[2],yv[2],phiv[2];
  double pd = 1.0,p,L,psid = (2*pi)/3;;
    double delphi,k1=0.9;
    double k2=0.38;
  double vf_new, wf_new;
  double gama, beta, psi;
 double angle_read1,angle_read2,angle_pre1,angle_pre2;
  double l, ld=1;
  vl=0.1;
  wl = dtor(5);
  double count,count1;
  
  for(;;)
    {
		count++;
		count1++;
      f1=fopen("formation_fl.txt","a");
      p1.SetSpeed(vl, wl);
      r1.Read();  // r1 leader r2,r3 follower
      r2.Read();  
     // r3.Read();  r3.Read();
      
      xl=p1.GetXPos(); yl=p1.GetYPos();  // angle will come in radian

      xf=-1+p2.GetXPos(); yf=-1+p2.GetYPos(); 
      	delphi=atan2((yl-yf-d*sin(phif)),(xl-xf-d*cos(phif)));
      /////////////////////////
      		angle_read1 = p1.GetYaw(); 
		angle_read2=p2.GetYaw(); 
		if (count==1)
		{
		angle_pre1=angle_read1;
	   }
		if (count1==1)
		{
		angle_pre2=angle_read2;     
	}
		phil=     -angle_pre1+angle_read1;
		phif=     -angle_pre2+angle_read2;
     
		if (phil>=6.283185307)
		{
		count=0;	
			}
			if (phil<=-6.283185307)
		{
		count=0;	
			}
			if (phif>=6.283185307)
		{
		count1=0;	
			}
				if (phif<=-6.283185307)
		{
		count1=0;	
			}
      ////////////////////////
      //xf1=p3.GetXPos(); yf1=p3.GetYPos();  phif1=p3.GetYaw();
     // p = sqrt(pow((xl-xf),2.0)+pow((yl-yf),2.0));
     // p_1 = sqrt(pow((xl-xf1),2.0)+pow((yl-yf1),2.0));
     // delphi = atan2((yl-yf),(xl-xf))-phif ;//-phid;
    //  delphi1 = atan2((yl-yf1),(xl-xf1))-phif1;

     
      //L = pd*cos(phid);
     //// L1 = pd1*cos(phid1);
     
    
      //vf = -k1*(L*pd- p*p *cos(delphi)) + vl ;//* cos(phil-phif);
      //wf = k1*sin(delphi-phid)+ wl*cos(phil-phif);

	
      //  wf = (k1*p/L)*sin(delphi-phid)+ (vl/L)*sin(phil-phif);

    

      //vf1 = -k1*(L1*pd- p_1*p_1 *cos(delphi1)) + vl;// * cos(phil-phif1);
      
     // wf1 = k1*sin(delphi1-phid1)+ wl*cos(phil-phif1);
       
	// printf("R2 velocity %lf \t %lf \n",vf,wf);
	//  printf("R3 velocity %lf \t %lf \n",vf1,wf1);
      // write commands to robot
      
      psi=dtor(180.0)-(phil-delphi);
      l=sqrt(pow((xl-xf-d*cos(phif)),2.0)+pow((yl-yf-d*sin(phif)),2.0));
      
 
      beta=phil-phif;
      gama=beta+psi;
      
      vf=cos(gama)*k1*(ld-l)+cos(gama)*cos(psi)*vl-l*sin(gama)*k2*(psid-psi)+sin(gama)*sin(psi)*vl-l*sin(gama)*wl;
      wf=(sin(gama)*k1*(ld-l)+cos(psi)*vl*sin(gama)+l*k2*cos(gama)*(psid-psi)-cos(gama)*sin(psi)*vl+l*cos(gama)*wl)/d;
      
      	if(vf>0.13)
		{
		vf_new=0.13;
	}
		else
		{
			if(vf<0)
			{
			vf_new=0.0;
		}
		else
		{
			vf_new=vf;
		}
		}
		///////////////////////////////////
			if(wf>dtor(15))
		{
		wf_new=dtor(15);
	}
		else
		{
		if(wf<-dtor(15))
			{
			wf_new=-dtor(15);
		}
		else
		{
			wf_new=wf;
		}
		}
		
        p2.SetSpeed(vf_new, wf_new);
      
      // p2.SetSpeed(vf, wf);
    //  p3.SetSpeed(vf1,wf1);
      // printf(" p  %lf \t phi %lf \t %lf \t %lf \n",p,rtod(delphi),vf,rtod(wf));
      // printf(" p1  %lf \t phi %lf \t %lf \t %lf \n \n",p_1,rtod(delphi1),vf1,rtod(wf1));
      //printf("p %lf \n",yt);
        //fprintf(f1,"%l lf \t delphi %lf \t vl  %lf \t wl %lf \t l1 %lf \t delphi1 %lf \t vf %lf \t  wf%lf \n",p,rtod(delphi),vl,wl,p_1,rtod(delphi1),vf,wf);
            //printf("%l lf \t delphi %lf \t vl  %lf \t wl %lf \t l1 %lf \t delphi1 %lf \t vf %lf \t  wf%lf \n",p,rtod(delphi),vl,wl,p_1,rtod(delphi1),vf,wf);
      fprintf(f1,"xl %lf \t yl %lf \t xf %lf \t yf %lf \t phil %lf \t phif %lf \t l %lf \n",xl,yl,xf,yf,phil,phif,l);
      fclose(f1);
      // sleep(1);
      
   printf("xl %lf \t yl %lf \t xf %lf \t yf %lf \t phil %lf \t phif %lf \t l %lf \n",xl,yl,xf,yf,phil,phif,l);
 
    }
  return 0;
}