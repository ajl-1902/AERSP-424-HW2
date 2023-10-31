#include <string>
#include <map>
#include <random>
#include "Plane.h"
using namespace std;

double Plane::getPos() { return pos; }
double Plane::getVel() { return vel; }
double Plane::getLoiterTime() { return loiter_time; }
string Plane::getOrigin() { return origin; }
string Plane::getDestination() { return destination; }
bool Plane::getAtSCE() { return at_SCE; }

void Plane::setVel(double vel)
{
	this->vel = vel;
}

void Plane::setLoiterTime(double loiter_time)
{
	this->loiter_time = loiter_time;
}

Plane::Plane(string from, string to)
{
	origin = from;
	destination = to;

	if (origin == "SCE")
		distance = this->flight_info[{origin, destination}];
	else distance = this->flight_info[{destination, origin}];

	pos = 0;
	vel = 0;
	wait_time = 0; 
	loiter_time = 0;
	at_SCE = 0;
}

Plane::~Plane() {}

void Plane::operate(double dt)
{
	if (loiter_time != 0) {
		loiter_time -= dt;
		if (loiter_time < 0) loiter_time = 0;
		return;
	}	
	else if (wait_time != 0)
	{
		wait_time -= dt;
		if (wait_time < 0) wait_time = 0;
		return;
	}
	else if (pos < distance)
	{
		pos += vel * dt;
		at_SCE = 0;
		return;
	}
	else if (destination == "SCE")
	{
		at_SCE = 1;
	}

	wait_time = time_on_ground();
	string temp = destination;
	destination = origin;
	origin = temp;
	pos = 0.0;
}

double Plane::distance_to_SCE()
{
	if (destination == "SCE")
		return distance - pos;
	else return 1000; 
	// Default return value of 0 was less than the established airspace distance
	// Caused outbound planes to loiter whenever more than two planes were near SCE (regardless of where they actually were)
}

string Plane::plane_type() { return "GA"; }

double Plane::draw_from_normal_dist(double mean, double standard_deviation)
{
	random_device rd{};
	mt19937 gen{ rd() };
	normal_distribution<> d{ mean, standard_deviation };
	return d(gen);
}