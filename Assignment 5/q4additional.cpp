#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d,node* next1){
        data=d;
        next=next1;}
    node(int d){
        data=d;
        next=nullptr;
    }
};

node* toll(vector<int> v){
    node* head=new node(v[0]);
    node* mover=head;
    for(int i=1;i<v.size();i++){
        node* temp=new node(v[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
int size(node* head){
    node* temp=head;
    int size=0;
    while(temp){
        temp=temp->next;
        size++;
    }
    return size;
}
node* rotateleftK(node* head,int k){
    node* temp=head;
    int cnt=0;
    int k2=k%size(head);
    int k1=size(head)-k2;
    queue<int> q;
    int f=size(head);
    while(f>0){
        if(cnt==k1){
            q.push(temp->data);
            temp->data=q.front();
            q.pop();
            temp=temp->next;
            f--;

        }else {
            q.push(temp->data);
            cnt++;
            temp=temp->next;
        }
        if(temp==nullptr){
            temp=head;
        }
    }
    return head;
}
void travel(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int> v={1,2,3,4,5};
    node * head=toll(v);
    head=rotateleftK(head,2);
    travel(head);
    return 0;
}