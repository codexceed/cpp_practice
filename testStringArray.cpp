#include<iostream>
#include<string>
using namespace std;


int main(){
	string *arr = new string[10];
	for(int i=0;i<10;i++){
		string temp;
		cin>>temp;
		arr[i] = temp;
}

for(int j=0;j<10;j++) cout<<arr[j]<<endl;

return 0;

}
