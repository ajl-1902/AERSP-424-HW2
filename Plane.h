#pragma once
#include <string>
#include <map>
using namespace std;

class Plane
{
protected:
	double wait_time;

private:
	double pos, vel, distance, loiter_time;
	bool at_SCE;
	string origin, destination;
	map<pair<string, string>, int> flight_info{
	{ make_pair("SCE", "PHL"),160 },
	{ make_pair("SCE", "ORD"),640 },
	{ make_pair("SCE", "EWR"),220 } }; // Pair of destination/origin airports used to access distance between them

public:
	Plane(string from, string to);
	virtual ~Plane();
	void operate(double dt);

	double getPos();
	double getVel();
	double getLoiterTime();
	string getOrigin();
	string getDestination();
	bool getAtSCE();

	void setVel(double vel);
	void setLoiterTime(double loiter_time);

	double distance_to_SCE();
	virtual double time_on_ground() = 0; // Purely virtual - not used in the base class, and is overwritten by derived classes
	virtual string plane_type();
	static double draw_from_normal_dist(double mean, double standard_deviation);
};