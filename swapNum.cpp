#include<iostream>
using namespace std;

void swapNum(int &x, int &y){
	x^=y;
	y=x^y;
	x^=y;
}

int main(){
	int a,b;
	cin>>a>>b;
	swapNum(a,b);
	cout<<a<<" "<<b;
	return 0;
}
