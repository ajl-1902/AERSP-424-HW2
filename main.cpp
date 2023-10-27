#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Airliner.h"
#include "GeneralAviation.h"
#include "ATC.h"
using namespace std;


int main(int argc, char** argv)
{
	Airliner AA5915("AA", "SCE", "PHL");
	Airliner UA5236("UA", "SCE", "ORD");
	Airliner UA4465("UA", "SCE", "EWR");
	Airliner AA6240("AA", "SCE", "ORD");
	GeneralAviation GA1("SCE", "PHL");
	GeneralAviation GA2("SCE", "EWR");
	GeneralAviation GA3("SCE", "ORD");

	AA5915.setVel(470.0/3600.0);
	UA5236.setVel(515.0/3600.0);
	UA4465.setVel(480.0/3600.0);
	AA6240.setVel(500.0/3600.0);
	GA1.setVel(140.0/3600.0);
	GA2.setVel(160.0/3600.0);
	GA3.setVel(180.0/3600.0);

	ATC atc;
	atc.register_plane(&AA5915);
	atc.register_plane(&UA5236);
	atc.register_plane(&UA4465);
	atc.register_plane(&AA6240);
	atc.register_plane(&GA1);
	atc.register_plane(&GA2);
	atc.register_plane(&GA3);

	double dt = 10.0;
	while (true)
	{
		AA5915.operate(dt);
		atc.control_traffic();
		UA5236.operate(dt);
		atc.control_traffic();
		UA4465.operate(dt);
		atc.control_traffic();
		AA6240.operate(dt);
		atc.control_traffic();
		GA1.operate(dt);
		atc.control_traffic();
		GA2.operate(dt);
		atc.control_traffic();
		GA3.operate(dt);
		atc.control_traffic();

		cout << AA5915.getPos() << "\t\t" << UA5236.getPos() << "\t\t" << UA4465.getPos() << "\t\t" << AA6240.getPos() << "\t\t"
			<< GA1.getPos() << "\t\t" << GA2.getPos() << "\t\t" << GA3.getPos() << endl;
	}
}