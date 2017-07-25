#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
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

long long merge(vector<int> &arr, int l, int h){
    int aux[h-l+1];
    int mid = (l+h)/2;
    int i=l, j=mid+1, k=0;
    long long count=0;


    while(i<=mid&&j<=h){
        if(arr[j]<arr[i]){
            aux[k] = arr[j];
            j++;
            count+=mid-i+1;
        }
        else{
            aux[k] = arr[i];
            i++;
        }
        k++;
    }
    while(i<=mid){
        aux[k] = arr[i];
        i++;
        k++;
    }
    while(j<=h){
        aux[k] = arr[j];
        j++;
        k++;
    }

    k=0;
    for(int x=l;x<=h;x++){
        arr[x] = aux[k];
        k++;
    }

    return count;
}

long long mergeSort(vector<int> &arr, int lo, int hi){
    if(lo>=hi) return 0;

    int mid = (lo+hi)/2;
    long long count=0;

    count+=mergeSort(arr, lo, mid);
    count+=mergeSort(arr, mid+1, hi);
    count+=merge(arr, lo, hi);

    return count;
}

long long count_inversions(vector<int> &a) {

    return mergeSort(a, 0, a.size()-1);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
