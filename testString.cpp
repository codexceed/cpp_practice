#include<iostream>
#include<string>
using namespace std;

int main(){
    char x = 'z';
    int n=2;
    char z = (int)x-n;

    for(int i=0;i<1000;i++){
        cout<<z<<" "<<(int)z<<endl;
        int temp= (int)z;
        z = temp+1;
    }

    return 0;
}
