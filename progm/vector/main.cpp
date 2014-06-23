#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<vector>
using namespace cv;
using namespace std;
	
int main()
{

	double x1,x2,y1,y2;
	cin >>x1>>x2>>y1>>y2;
	if(y2 - y1>0 &&  x2 - x1>0)
	{
		double angle = atan2(y2 - y1, x2 - x1) * 180.0 / CV_PI;
	}
	
	cout << angle;
	

	
}      

