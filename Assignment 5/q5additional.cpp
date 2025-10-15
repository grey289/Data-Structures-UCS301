#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int value1;
    int value2;
    node* next;
    node(int val1,node* temp,int val2){
        next=temp;
        value1=val1;
        value2=val2;
    }
    node(int val1,int val2){
        value1=val1;
        value2=val2;
        next=nullptr;
    }
};
node* convert(vector <pair<int,int>> v){
    node * head= new node(v[0].first,v[0].second);
    node* mover=head;
    for(int i=1;i<v.size();i++){
        node* temp= new node(v[i].first,v[i].second);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
node* adder(node* head1,node* head2){
    node* temp1=head1;
    node* temp2=head2;
    map<int,int> mpp;
    while(temp1){
        mpp[temp1->value1]+=temp1->value2;
        temp1=temp1->next;
    }
    while(temp2){
        mpp[temp2->value1]+=temp2->value2;
        temp2=temp2->next;
    }
     if (mpp.empty()) {
        return nullptr;
    }

    node* newHead = nullptr;
    node* tail = nullptr;

    // Iterate through each key-value pair in the map
    for (const auto& pair : mpp) {
        int key = pair.first;
        int summed_value = pair.second;

        // Create a new node with the aggregated data
        node* newNode = new node(key, summed_value);

        if (newHead == nullptr) {
            // If this is the first node we're creating
            newHead = newNode;
            tail = newNode;
        } else {
            // For all subsequent nodes, append to the end of the list
            tail->next = newNode;
            tail = tail->next; // Move the tail pointer forward
        }
    }

    return newHead;
}
   
void printer(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->value1<<":"<<temp->value2<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    vector <pair<int,int>> v1={{2,5},{1,4},{0,2}};
    vector <pair<int,int>> v2={{1,5},{0,5}};
    node* head1=convert(v1);
    node* head2=convert(v2);
    printer(head1);
    printer(head2);
    cout<<"Addition of LL"<<endl;
    
    node* head3=adder(head1,head2);
    printer(head3);

    return 0; 
}