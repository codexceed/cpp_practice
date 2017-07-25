#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<string> vec;
	string temp;
	for(int i=0;i<5;i++){
	cin>>temp;
	vec.push_back(temp);
}
	for(vector<string>::iterator it=vec.begin();it!=vec.end();it++)
		cout<<*it<<endl;
return 0;
}
