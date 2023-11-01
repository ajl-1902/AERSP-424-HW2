#include <iostream>
#include <string>
#include "Airliner.h"
#include "GeneralAviation.h"
#include "ATC.h"
#include "SDL.h"
#include "HW2_Visualizer.h"
using namespace std;


int main(int argc, char** argv)
{
	HW2_VIZ viz;

	// Instantiation of aircraft objects
	Airliner AA5915("AA", "SCE", "PHL");
	Airliner UA5236("UA", "SCE", "ORD");
	Airliner UA4465("UA", "SCE", "EWR");
	Airliner AA6240("AA", "SCE", "ORD");
	GeneralAviation GA1("SCE", "PHL");
	GeneralAviation GA2("SCE", "EWR");
	GeneralAviation GA3("SCE", "ORD");

	// Set individual aircraft velocity (units of miles/s)
	AA5915.setVel(470.0/3600.0);
	UA5236.setVel(515.0/3600.0);
	UA4465.setVel(480.0/3600.0);
	AA6240.setVel(500.0/3600.0);
	GA1.setVel(140.0/3600.0);
	GA2.setVel(160.0/3600.0);
	GA3.setVel(180.0/3600.0);

	// Instantiating air traffic control object and registering aircraft (passed by reference)
	ATC atc;
	atc.register_plane(&AA5915);
	atc.register_plane(&UA5236);
	atc.register_plane(&UA4465);
	atc.register_plane(&AA6240);
	atc.register_plane(&GA1);
	atc.register_plane(&GA2);
	atc.register_plane(&GA3);

	// Calculating aircraft positions and controlling traffic as needed
	double dt = 10.0;
	while (true)
	{
		AA5915.operate(dt);
		atc.control_traffic();
		viz.visualize_plane(AA5915.plane_type(), AA5915.getOrigin(), AA5915.getDestination(), AA5915.getPos());

		UA5236.operate(dt);
		atc.control_traffic();
		viz.visualize_plane(UA5236.plane_type(), UA5236.getOrigin(), UA5236.getDestination(), UA5236.getPos());

		UA4465.operate(dt);
		atc.control_traffic();
		viz.visualize_plane(UA4465.plane_type(), UA4465.getOrigin(), UA4465.getDestination(), UA4465.getPos());

		AA6240.operate(dt);
		atc.control_traffic();
		viz.visualize_plane(AA6240.plane_type(), AA6240.getOrigin(), AA6240.getDestination(), AA6240.getPos());

		GA1.operate(dt);
		atc.control_traffic();
		viz.visualize_plane(GA1.plane_type(), GA1.getOrigin(), GA1.getDestination(), GA1.getPos());

		GA2.operate(dt);
		atc.control_traffic();
		viz.visualize_plane(GA2.plane_type(), GA2.getOrigin(), GA2.getDestination(), GA2.getPos());

		GA3.operate(dt);
		atc.control_traffic();
		viz.visualize_plane(GA3.plane_type(), GA3.getOrigin(), GA3.getDestination(), GA3.getPos());

		viz.update(dt);

		// Output for Q5/Q7
		//cout << AA5915.getPos() << "\t\t" << UA5236.getPos() << "\t\t" << UA4465.getPos() << "\t\t" << AA6240.getPos() << "\t\t"
		//	<< GA1.getPos() << "\t\t" << GA2.getPos() << "\t\t" << GA3.getPos() << endl;
	}
}