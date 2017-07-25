#include<iostream>
using namespace std;

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct Node{
    int data;
    Node *next;
};

class linkedList{
    Node *head=NULL, *tail=NULL;
public:
    void enqueue(int data){
        Node *newNode = new Node;
        newNode->data = data;
        if(head==NULL){
            tail = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    Node* findNodeByVal(int val){
        Node *probe = head;
        while(probe){
            if(probe->data==val)return probe;
        }
        return NULL;
    }

    void dequeue(){
        if(head==tail)delete(head);
        else if(head==NULL)cout<<"Empty List!\n";
        else{
            Node *temp = head;
            while(temp->next!=tail)temp = temp->next;
            temp->next = NULL;
            delete(tail);
            tail = temp;
        }
    }

    void showList(){
        if(head==NULL){
            cout<<"Empty List!\n";
            return;
        }
        Node *currNode = head;

        while(currNode){
            cout<<currNode->data<<" ";
            currNode = currNode->next;
        }
        cout<<"\n";
    }
};


#endif // LINKEDLIST_H_INCLUDED
