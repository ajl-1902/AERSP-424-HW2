#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main()
{
	map<pair<string, string>, int> flight_info{
		{ make_pair("SCE", "PHL"),160 },
		{ make_pair("SCE", "ORD"),640 },
		{ make_pair("SCE", "EWR"),220 } };
	cout << flight_info[make_pair("SCE", "PHL")] << endl;
}