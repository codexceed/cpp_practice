#include<iostream>
using namespace std;

void swap(int &a, int &b){
	a+=b;
	b = a-b;
	a = a-b;
}


void waveSort(int *arr, int n){
	for(int i=1;i<n;i+=2){
		if(arr[i]>arr[i-1])swap(arr[i], arr[i-1]);
		if(arr[i]>arr[i+1])swap(arr[i], arr[i+1]);
	}

}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	waveSort(arr, n);
	for(int j=0;j<n;j++)
	cout<<arr[j]<<" ";
	return 0;
}
