#include <string>
#include "GeneralAviation.h"
#include "Plane.h"
using namespace std;

// "from" and "to" strings taken as inputs into Airliner constructor and passed back to the base class
GeneralAviation::GeneralAviation(string from, string to) :Plane(from, to) {}

GeneralAviation::~GeneralAviation() {}

double GeneralAviation::time_on_ground() // Overrides purely virtual time_on_ground() function in the base class
{
	wait_time = draw_from_normal_dist(600, 60);
	return wait_time;
}