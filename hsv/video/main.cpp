#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
/// Global variables

/*int threshold_value = 0;
int threshold_type = 3;;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;*/

Mat src, src_gray, dst;
//char* window_name = "Threshold Demo";




int main()
{
    VideoCapture cap(-1);     // get 'any' cam
    while( cap.isOpened() )   // check if we succeeded
    {
        Mat src;

 if ( ! cap.read(src) )
            break;

/// Convert the image to Gray
 /* cvtColor( src, src_gray, CV_RGB2GRAY );

  /// Create a window to display results*/
  namedWindow( "abc", CV_WINDOW_AUTOSIZE );

  imshow( "abc", src );

    }
    return 0;
}



