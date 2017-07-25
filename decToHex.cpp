#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;
string decToHex(int n){
    int hexVal;
    string s;
    map <int, char> hexDic = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

    while(n>0){
        hexVal = n%16;
        n/=16;
        s=hexDic[hexVal]+s;
    }
    return s;
}
int main(){
    int n, hexVal;
    cin>>n;
    cout<<decToHex(n);
    return 0;
}
