#include <string>
#include "GeneralAviation.h"
#include "Plane.h"
using namespace std;

GeneralAviation::GeneralAviation(string from, string to) :Plane(from, to) {}

GeneralAviation::~GeneralAviation() {}

double GeneralAviation::time_on_ground()
{
	wait_time = draw_from_normal_dist(600, 60);
	return wait_time;
}