#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> strSplit(string s, char del=' '){
	vector<string> out_arr;
	string word;
	int i=0;
	while(s[i]){
        if(s[i]==del){
	    if(word!=""){
            out_arr.push_back(word);
            word="";}
            i++;
            continue;
        }
        word+=s[i];
        i++;
	}
	out_arr.push_back(word);
	return out_arr;

}

int main(){
	string x;
	getline(cin, x);
	vector<string> y;
	y = strSplit(x,'.');
	for(vector<string>::iterator it=y.begin();it!=y.end();it++)
		cout<<*it<<"\n";

	return 0;
}
