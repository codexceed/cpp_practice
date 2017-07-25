#include<iostream>
#include "linkedList.h"
using namespace std;

int main(){
	linkedList obj;
	obj.showList();
	obj.enqueue(4);
	obj.enqueue(3);
	obj.dequeue();
	obj.enqueue(5);
	obj.enqueue(3);
	obj.showList();
	obj.dequeue();
	obj.showList();
}
