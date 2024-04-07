/*wbc - damn simple webcam program.*/
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#define WIDTH 320
#define HEIGHT 240
#define WNAME "wbc"

using namespace cv;

int
main(void)
{
	
	//create video capture.
	VideoCapture cap ;
	
	
	//open default video device.
	cap.open(0);
	
	
	//error if cam can not be opened.
	if( ! cap.isOpened( ) )
	{
		std::cerr << "Can not open a cam.";
		return -1;
	}
	
	
	//create window for stream.
	namedWindow( WNAME , WINDOW_NORMAL );
	resizeWindow( WNAME , WIDTH,HEIGHT);
	
	
	//init variable for next video frame.
	Mat frame ;
	
	
	for(;;)
	{
		
		//read next video frame from device into "frame" variable.
		cap.read( frame);
		
		if( frame.empty( ) )
		{
			break ;
		}
		
		//show frame in window.
		imshow( WNAME , frame );
		
		
		//exit on "q" press.
		if ( waitKey(1) == 'q' ) {
			break;
		}
		
		
	};
	
	
	destroyAllWindows();
	
	//close webcam file.
	cap.release();
	
	return 0;
};