#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	map<string, map<string, int> > mymap;
	mymap["yolo"]["swag"] = 1;
	mymap["yolo"]["woohoo"] = 2;
	cout<<mymap["yolo"]["swag"];
	return 0;
}
