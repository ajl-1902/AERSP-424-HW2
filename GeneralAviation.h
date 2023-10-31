#pragma once
#include <string>
#include "Plane.h"
using namespace std;

class GeneralAviation :public Plane
{
public:
	GeneralAviation(string from, string to);
	~GeneralAviation();
	double time_on_ground();
};