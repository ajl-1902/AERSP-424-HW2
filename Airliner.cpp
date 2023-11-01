#include <string>
#include "Airliner.h"
#include "Plane.h"
using namespace std;

// "from" and "to" strings taken as inputs into Airliner constructor and passed back to the base class
Airliner::Airliner(string Airline, string from, string to) :Plane(from, to)
{
	this->Airline = Airline;
}

Airliner::~Airliner() {}

string Airliner::plane_type() { return Airline; }

double Airliner::time_on_ground() // Overrides purely virtual time_on_ground() function in the base class
{
	wait_time = draw_from_normal_dist(1800, 600);
	return wait_time;
}