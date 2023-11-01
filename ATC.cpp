#include <vector>
#include "ATC.h"
#include "Plane.h"
using namespace std;

ATC::ATC() {}
ATC::~ATC() {}

void ATC::register_plane(Plane* Aircraft)
{
	registered_planes.push_back(Aircraft); // Pointer to aircraft object stored in the vector registered_planes
}

void ATC::control_traffic()
{
	unsigned int landed_planes = 0;
	int i = 0;

	while (i < size(registered_planes))
	{
		landed_planes += (*registered_planes[i]).getAtSCE(); // Contents of vector at index i must be dereferenced to access info
		i++;
	}

	if (landed_planes >= this->MAX_LANDED_PLANE_NUM) { i = 0; }
	else return;

	for (i; i < size(registered_planes); i++)
	{
		if ((*registered_planes[i]).getAtSCE() == 0 && (*registered_planes[i]).distance_to_SCE() <= AIRSPACE_DISTANCE 
			&& (*registered_planes[i]).getLoiterTime() == 0) 
			// Same method as above - vector must be dereferenced to access functions in Plane class
		{
			(*registered_planes[i]).setLoiterTime(100);
		}
	}
	return;
}