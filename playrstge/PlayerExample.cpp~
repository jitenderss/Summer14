/* Chris Burbride
 * cburbridge@gmail.com
 * 15/09/2009
 *
 * PlayerExample
 * -------------
 *
 * Example code for controlling a robot using Player / Stage.
 *
 *
 */
#include <player-2.1/libplayerc++/playerc++.h>
#include <iostream>
#include<linux/videodev.h>
using namespace std;

int main(int argc, char** argv) {
	// Create a Player client connection
	#define HOST "localhost"	// The player server; localhost if running on the robot
								// or the robot IP if the program is running remotely.
	#define PORT 6665			// The port that player listens on, defaults 6665.
	PlayerCc::PlayerClient client(HOST, PORT);

	// Create a camera connection
	// The second parameter is the index of the camera you want, as written in the
	// config file. This applies for the position, laser and sonar also.
	PlayerCc::CameraProxy camera(&client, 0);

	// Create a connection to the position system
	// This is used to control the robot velcoities and to read the odometry
	PlayerCc::Position2dProxy position(&client,0);

	// Create a connection to the laser scanner
	PlayerCc::LaserProxy laser(&client,0);

	// Create a sonar proxy
	PlayerCc::SonarProxy sonar(&client,0);


	// IMPORTANT.
	// The data sent over the network is not decoded until you call client Read
	// This means that client.Read() must be called somewhere in your main loop
	// otherwise you wont be getting new data.
	// Here I have made several calls because the first messages received by the
	// client sometimes don't have the image size data, so when working with the
	// camera I usually do this. This is maybe a bad hack :-|
	client.Read();
	/*client.Read();
	client.Read();
	client.Read();*/


	// Control the robot as follows:
	float linear=0.1;
	float angular=0.1;
	position.SetSpeed(linear,angular);

	// Read the odometry as follows:
	float odomX,odomY,odomTh;
	odomX=position.GetXPos();
	odomY=position.GetYPos();
	odomTh=position.GetYaw();
	cout << "Odometry readings: " << endl;
	cout << "(" << odomX << ", " << odomY << ", " << odomTh << ")" << endl << endl;

	// Read the laser values as follows:
	int MAXLASERS = 360; // The maximum values the laser returns; ours is configured for 180 degrees at 0.5 deg/reading
	cout << "Laser readings: " << endl;
	for (int i=0;i<MAXLASERS;i++) {
		cout << laser[i] << " ";
	}
	cout << endl << endl;

	// Read the sonar values:
	int MAXSONARS = 24; // How many sonars do we have? 24
	cout << "Sonar readings: " << endl;
	for (int i=0;i<MAXSONARS;i++) {
		cout << sonar[i] << " ";
	}
	cout << endl << endl;


	// Getting the camera image
	if (camera.GetCompression()) {
		cout << "Image compressed. " << endl;
		camera.Decompress(); // Decompress the image (if we conpressed it in the player config file)
	}
	cout << "Image width: " << camera.GetWidth() << endl;
	cout << "Image height: " << camera.GetWidth() << endl;
	cout << "Image depth: " << camera.GetDepth() << endl;
	// The image date can be coppied to some already alocated memory
	// eg.
	unsigned char *imagedata = new unsigned char[camera.GetImageSize()];
	camera.GetImage(imagedata);
	// Now write the image to file or use the data some how
	// The format of the data is RGBRGBRGBRGBRGB row major
	FILE *file = fopen("testimage.ppm","w");
	fprintf(file, "P6\n%d %d\n255\n",camera.GetWidth(),camera.GetHeight());
	fwrite(imagedata,camera.GetImageSize(),1,file);
	fclose(file);
	delete imagedata;

	// Thats all :-)
	position.SetSpeed(0,0);

}
