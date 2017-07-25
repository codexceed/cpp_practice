#include<iostream>
#include<vector>
using namespace std;

class Stack{
    int top;
    vector<int> stk;

public:
    Stack(){top=-1;}
    friend class stackSort;
    void push(int val){
        cout<<"pushing"<<endl;\
        cout<<"stk["<<top+1<<"]="<<val<<endl;
        if(top<stk.size()-1)stk[++top] = val;
        else{
          stk.push_back(val);
          cout<<"val="<<val<<" stk.size()"<<stk.size()<<endl;
          cout<<"extend vector: "<<"stk["<<top+1<<"]="<<stk[top+1]<<endl;
          top++;
        }
    }

    int pop(){
        top--;
        return stk[top+1];
    }

    int showTop(){
        return stk[top];
    }

    void showStack(){
        for(int i=0;i<=top;i++)cout<<stk[i]<<" ";
        cout<<"\n";
    }

    bool isempty(){
        return top<0?true:false;
    }
};

class stackSort{
public:
    void sortedInsert(Stack& obj, int val){
        cout<<"Inserting "<<val<<" into ";
        obj.showStack();
        if(obj.showTop()<=val||obj.isempty())obj.push(val);
        else{
            cout<<obj.showTop()<<">"<<val<<endl;
            int temp = obj.pop();

            sortedInsert(obj, val);
            obj.push(temp);
        }
    }
    void sortStack(Stack& obj){
        int temp = obj.pop();
        sortStack(obj);
        sortedInsert(obj, temp);
    }
};

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int val;
        Stack stk;

        for(int j=0;j<n;j++){
            cin>>val;
            stk.push(val);
        }
        stk.showStack();
        stackSort sorter;
        sorter.sortedInsert(stk, 0);
        stk.showStack();
    }
}
