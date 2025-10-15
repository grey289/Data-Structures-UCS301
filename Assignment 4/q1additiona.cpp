#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//stack using linkedlist
class node{
    public:
    int value;
    node* next;
    node(int val,node* temp){
        value=val;
        next=temp;
    }
    node(int val){
        value=val;
        next=nullptr;
    }
};
node* stackerpush(node* top,int val){
 node* temp=new node(val,top);
 top=temp;
delete temp;
 return top;   
}
node* stackerpop(node* top){
top=top->next;
return top;
}
int main()
{
    
    return 0; 
}