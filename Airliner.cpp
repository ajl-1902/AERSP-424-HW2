#include <string>
#include "Airliner.h"
#include "Plane.h"
using namespace std;

Airliner::Airliner(string Airline, string from, string to) :Plane(from, to)
{
	this->Airline = Airline;
}

Airliner::~Airliner() {}

string Airliner::plane_type() { return Airline; }

double Airliner::time_on_ground()
{
	wait_time = draw_from_normal_dist(1800, 600);
	return wait_time;
}