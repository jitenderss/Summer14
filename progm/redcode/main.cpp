#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if(argc !=2)
    {
     cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(! image.data)
    {
      cout << "Could not open or find the image"<< endl;
      return -1;
    }
     
  for(int j=0;j<image.rows;j++) 
{
  for (int i=0;i<image.cols;i++)
  {
	if( image.at<Vec3b>(j,i)[2] < 150 || image.at<Vec3b>(j,i)[1]>50 || image.at<Vec3b>(j,i)[0]>50) 
			{image.at<Vec3b>(j,i)[2] = 0;} 
     image.at<Vec3b>(j,i)[0] = 0;  //turn the pixel value @ (k,i) to yellow (0,255,255)
			image.at<Vec3b>(j,i)[1] = 0;
			
			
       /*image.at<uchar>(j,i) = 255; //white*/
  }
}
namedWindow("Display window", CV_WINDOW_AUTOSIZE);
imshow("Display Window",image);
    
    
 
    waitKey(0);
    return 0;
}


