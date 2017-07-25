#include<iostream>
#include<map>
using namespace std;


//Node to form the linked list
struct Node{
    int key, val;
    Node *next, *prev;
};


//Declare class name before declaring friend
class lruCache;


//Class to implement linked list
class linkedList{
    int listSize, maxSize;
    Node *head, *tail;

public:

    //Declare lruache as friend to provide access to linkedList private members
    friend lruCache;
    linkedList(int n){listSize=0;maxSize=n;}
    void dequeue(){
        if(head==NULL)return;
        Node *temp = tail;
        if(head!=tail){
            tail = temp->prev;
            tail->next = NULL;
        }
        delete temp;
    }
    void enqueue(int key, int val){
        Node *newNode = new Node;
        newNode->val = val;
        newNode->key = key;
        if(head==NULL){
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        listSize++;
    }
};

//LRU class
class lruCache{
    linkedList *obj;  //linkedList obj to be referred during LRU caching, declared as pointer so as to use it as member while using its constructor later on in lruCache constructor.
    //Cannot declare as object as that would call the default linkedList constructor, thus throwing error at a constructor call in lruCache constructor.
    map<int, Node*> listMap;   //map of key to node pointers to keep track of keys in cache
public:
    lruCache(int cacheSize){obj = new linkedList(cacheSize);}
    //function to implement LRU caching
    void lruReferPage(int key){
        //Check if key exists in mapping table of the cache
        if(listMap.size()==0||listMap.find(key)==listMap.end()){
            cout<<"Key not in cache. Please enter a value:";
            int val;
            cin>>val;
            obj->enqueue(key, val);

            //if list size increases beyond the maximum cache size, bring it down.
            if(obj->listSize>obj->maxSize){
                listMap.erase(obj->tail->key);
                obj->dequeue();
                obj->listSize--;
        }
            // the newly added key is least recently used, and hence is at the head of list
            listMap[key] = obj->head;
        }
        else{
            //If key is found, show its value
            cout<<"Key is found! Value is:"<<listMap[key]->val<<"\n";

            //Check if the key is at the head. If yes, then no need to do modify the list
            if(listMap[key]!=obj->head){

                    //if tail is not key, then we must alter the prev pointer for the node comeing after key node
                    if(listMap[key]!=obj->tail){
                        listMap[key]->next->prev = listMap[key]->prev;
                    }

                    //if tail is key, then point tail to the prev node of tail
                    else{
                        obj->tail = listMap[key]->prev;
                    }

                    //adjust pointers to rearrange key at head of list
                    listMap[key]->prev->next = listMap[key]->next;
                    listMap[key]->next = obj->head;
                    obj->head->prev = listMap[key];
                    listMap[key]->prev = NULL;
                    obj->head = listMap[key];
            }
        }
    }


    //print the Cached keys
    void showList(){
        Node *temp = obj->head;
        while(temp){
            cout<<temp->key<<" ";
            temp = temp->next;
        }
    }
};




int main(){
    int q, key, cacheSize;
    cout<<"Enter number of queries:";
    cin>>q;
    cout<<"Enter cache size:";
    cin>>cacheSize;
    lruCache lru = lruCache(cacheSize);
    for(int i=0;i<q;i++){
        cout<<"Enter key:";
        cin>>key;
        lru.lruReferPage(key);
        cout<<"Current Cache keys:";
        lru.showList();
    }

    return 0;

}
