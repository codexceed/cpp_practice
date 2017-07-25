#include<iostream>
#include<string>
using namespace std;

string getNextWord(string x, int start){
	int i = start;
    string out_str;
    while(x[i]!=' '){
        out_str+=x[i];
        i++;
    }
    return out_str;
}

int main(){
cout<<'"'<<endl;	
	string x = "yolo swag woohoo!";
	cout<<getNextWord(x, 5)<<endl;
	int i=0;
	if(true==1)cout<<"pompom";
	while(x[i]){
	cout<<x[i]<<endl;
	i++;
}
	return 0;
}
