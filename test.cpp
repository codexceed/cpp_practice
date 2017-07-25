#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next, *prev;
};

Node* addNode(Node *head, int data){
    Node *newNode = new Node;
    newNode->data = data;
    if(head==NULL){
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }


    return head;
}

void setNext(Node* A, Node* B){
    A->next = B;

}

Node* makeLoop(Node* head){
    Node *temp = head, *temp1;
    int t = 0;
    while(temp->next!=NULL){
        temp = temp->next;
        if(t==5)
            temp1 = temp;
        t++;
    }

    temp->next = temp1;
    return head;
}

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL)
        return false;
    Node* slow, *fast;
    slow = head;
    fast = head->next;

    while(fast!=NULL||fast->next!=NULL){
        if(slow==fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.

    Node* newNode = new Node;
    newNode->data = data;
    Node* temp = head;

    while(temp!=NULL){
        if(temp->data>newNode->data){
            newNode->next = temp;
            if(temp==head){
                head = newNode;
            }
            else{
                temp->prev->next = newNode;
                newNode->prev = temp->prev;
            }
            temp->prev = newNode;
            break;
        }
       if(temp->next==NULL){
           temp->next = newNode;
           newNode->prev = temp;
           break;
       }
       temp = temp->next;
    }
    return head;
}

int main(){

    int n;

	cout<<"Enter number of values:\n";
	cin>>n;
	Node* newList=NULL;
	for(int i=0;i<n;i++){
        newList = addNode(newList, i);
	}

	newList = SortedInsert(newList, 5);

	printList(newList);

    Node *temp1 = NULL;

    if(16>16)
        cout<<"yolo";




	return 0;
}
