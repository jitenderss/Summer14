#include <iostream>
#include "cv.h"
#include "highgui.h"

using namespace std;

int main( int argc, char** argv )

{
// Create an IplImage object *image 
IplImage *source = cvLoadImage( argv[1]);
// Here we retrieve a percentage value to a integer
int percent = atoi(argv[3]);

// declare a destination IplImage object with correct size, depth and channels
      IplImage *destination = cvCreateImage
( cvSize((int)((source->width*percent)/100) , (int)((source->height*percent)/100) ),
                                     source->depth, source->nChannels );

//use cvResize to resize source to a destination image
cvResize(source, destination);

// save image with a name supplied with a second argument
      cvSaveImage( argv[2], destination );



return 0;

}
