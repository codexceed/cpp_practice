#include <iostream>
using namespace std;

bool checkPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    cout<<"Enter number of queries: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(checkPrime(temp))
            cout<<"Prime"<<endl;
        else cout<<"Not Prime"<<endl;
    }
}
