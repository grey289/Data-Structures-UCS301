#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int val,node* temp){
        this->val=val;
        next=temp;
    }
    node(int value){
        val=value;
        next=nullptr;
    }
};
node* removeloop(node* head){
    if(head==NULL) return head;
    if(head->next==nullptr) return head;
    node* temp=head;
    unordered_set <node*> visited;
    visited.insert(temp);
    while(temp){
        if(visited.find(temp->next)==visited.end()){
            visited.insert(temp->next);
            temp=temp->next;
        }else {
            temp->next=nullptr;
            break;
        }
    }
    return head;
}
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

int main()
{
    vector <int> v1={1,2,3,4,5};
    node * head= convertvecttoll(v1);
    head=removeloop(head);
    return 0; 
}