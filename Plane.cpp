#include <string>
#include <map>
#include <random>
#include <vector>
#include "Plane.h"
using namespace std;

map<pair<string, string>, int> flight_info{
	{ make_pair("SCE", "PHL"),160 },
	{ make_pair("SCE", "ORD"),640 },
	{ make_pair("SCE", "EWR"),220 } };

//vector<tuple<string, string, int>> vec{
//	make_tuple("SCE", "PHL", 160),
//	make_tuple("SCE", "ORD", 640),
//	make_tuple("SCE", "EWR", 220) };

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

	if (from == "SCE")
		distance = flight_info[make_pair(from, to)];
	else distance = flight_info[make_pair(to, from)];
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
	}	
	else if (wait_time != 0)
	{
		wait_time -= dt;
		if (wait_time < 0) wait_time = 0;
	}
	else if (pos < distance)
	{
		pos += vel * dt;
		at_SCE = 0;
	}
	else if (destination == "SCE")
		at_SCE = 1;

	time_on_ground();
	string temp = origin;
	destination = origin;
	origin = temp;
	pos = 0.0;
}

double Plane::distance_to_SCE()
{
	if (destination == "SCE")
		return distance - pos;
	else return 0;
}

//double Plane::time_on_ground() { return 0; }
string Plane::plane_type() { return "GA"; }

double Plane::draw_from_normal_dist(double mean, double standard_deviation)
{
	random_device rd{};
	mt19937 gen{ rd() };
	normal_distribution<> d{ mean, standard_deviation };
	return d(gen);
}