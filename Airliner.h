#pragma once
#include <string>
#include "Plane.h"
using namespace std;

class Airliner:public Plane
{
private:
	string Airline;

public:
	Airliner(string Airline, string from, string to);
	~Airliner();
	string plane_type();
	double time_on_ground();
};