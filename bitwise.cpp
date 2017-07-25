#include<iostream>
using namespace std;

int main(){
	int a,b;
	a = 12;
	b = 15;
	a^=b,b=a^b,a^=b;
	cout<<a<<b;
	return 0;
}
