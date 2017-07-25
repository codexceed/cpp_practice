#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector <int> vec;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    int x, a, b;
    cin>>x;
    vec.erase(vec.begin()+x-1);
    cin>>a>>b;
    vec.erase(vec.begin()+a-1, vec.begin()+b);

    for(vector <int>::iterator it=vec.begin();it!=vec.end();++it)
        cout<<*it<<" ";

    return 0;
}
