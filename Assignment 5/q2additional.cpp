#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int d, node* next1){
        data=d;
        next=next1;
    }
    node(int d){
        data=d;
        next=nullptr;
    }
};
node* convertvecttoll(vector <int> & arr){
    node* head= new node(arr[0]);
    node *mover=head;
    for (int i=1; i<arr.size();i++){
        node* temp= new node(arr[i]);
        mover->next=temp;
        mover=mover->next; //mover=temp;
    }
    return head;
}
void travell(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
node* revk(node* head, int k){
    stack<int> s;
    node* temp=head;
    int cnt=0;
    node* front=head;
    while(front){
        if(cnt==k){
            while(cnt>0){
            temp->data=s.top();
            s.pop();
            temp=temp->next;
            cnt--;}
        }else{
        s.push(front->data);
        front=front->next;
        cnt++;}
    }
    return head;
}
int main(){
    vector <int> v={1,2,3,4,5};
    node* head=convertvecttoll(v);
    head=revk(head,3);
    travell(head);
    return 0;
}