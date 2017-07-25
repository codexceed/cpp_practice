#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct textOb{
    map<string, string> attrib;
    vector<textOb*> subObs;
    
};



int main() {
    int n,q;
    cin>>n>>q;
    vector<string>  hrml;
    string temp;
    getline(cin, temp);
    for(int i=0;i<n;i++){
        getline(cin, temp);
        cout<<i;
        hrml.push_back(temp);
    }
    
    

    return 0;
}

