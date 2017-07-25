#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <regex>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool findMatch(string c, string n){
    if(n.substr(0,c.size())==c)
        return true;
    return false;
}
int main(){
    int n;
    cin >> n;
    vector <string> vec;

    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op=="add")
            vec.push_back(contact);
        else{
            int count = 0;
            for(vector<string>::iterator it=vec.begin();it!=vec.end();it++){
                if(findMatch(contact, *it))
                    count++;
            }
            cout<<count<<endl;
        }
    }
    return 0;
}
