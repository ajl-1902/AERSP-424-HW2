#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main()
{
	map<pair<string, string>, int> flight_info;
	flight_info.insert({ make_pair("SCE", "PHL"),160 });
	flight_info.insert({ make_pair("SCE", "ORD"),640 });
	flight_info.insert({ make_pair("SCE", "EWR"),220 });
}