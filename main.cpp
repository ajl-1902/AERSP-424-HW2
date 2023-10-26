#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Airliner.h"
#include "GeneralAviation.h"
using namespace std;


int main()
{
	Airliner AA5915("AA", "SCE", "PHL");
	Airliner UA5236("UA", "SCE", "ORD");
	Airliner UA4465("UA", "SCE", "EWR");
	Airliner AA6240("AA", "SCE", "ORD");
	GeneralAviation GA1("SCE", "PHL");
	GeneralAviation GA2("SCE", "EWR");
	GeneralAviation GA3("SCE", "ORD");
	
	AA5915.setVel(470);
	UA5236.setVel(515);
	UA4465.setVel(480);
	AA6240.setVel(500);
	GA1.setVel(140);
	GA2.setVel(160);
	GA3.setVel(180);

	double dt = 10/3600;
	while (true)
	{
		AA5915.operate(dt);
		UA5236.operate(dt);
		UA4465.operate(dt);
		AA6240.operate(dt);
		GA1.operate(dt);
		GA2.operate(dt);
		GA3.operate(dt);

		cout << AA5915.getPos() << " " << UA5236.getPos() << " " << UA4465.getPos() << " " << AA6240.getPos() << " "
			<< GA1.getPos() << " " << GA2.getPos() << " " << GA3.getPos() << endl;
	}
}