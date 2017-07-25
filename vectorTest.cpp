#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int x(int y){
    return y*2;
}
int main(){
    int a = 2;
    cout<<x(pow(a, 2));
    return 0;
}
