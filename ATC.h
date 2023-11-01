#pragma once
#include <string>
#include <vector>
#include "Airliner.h"
#include "GeneralAviation.h"
using namespace std;

class ATC
{
private:
	vector<Plane*> registered_planes; // registered_planes vector uses pointers to maintain parity with objects in main()
	unsigned int MAX_LANDED_PLANE_NUM = 2; 
	unsigned int AIRSPACE_DISTANCE = 50;

public:
	ATC();
	~ATC();

	void register_plane(Plane* Aircraft);
	void control_traffic();
};