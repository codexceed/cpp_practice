#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next, *bottom;
};

Node* createList(int val){
	Node* head = new Node;
	head->data = val;
	return head;
}

void addToList(Node* head, int val){
	Node *newNode = new Node, *temp;
	newNode->data = val;
	temp = head;
	while(temp->bottom)temp = temp->bottom;
	temp->bottom = newNode;
}

void traverseList(Node* head){
	if(head==NULL)cout<<"\n";
	cout<<head->data<<" ";
	traverseList(head->bottom);
	if(head->next)traverseList(head->next);	

}

int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		Node *head, *currHead;
		cin>>n;
		int num[n];
		for(int j=0;j<n;j++)
		cin>>num[j];
		

		for(int k=0;k<n;k++){
			int val;
			cin>>val;
			currHead = createList(val);
			for(int l=0;l<num[k]-1;l++){
				cin>>val;
				addToList(currHead, val);
			}
			if(!head)head = currHead;
			else{
				Node* temp = head;
				while(temp->next)temp = temp->next;
				temp->next = currHead;
			}	
		}
		
		
		traverseList(head);
	}
}
