#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d, node* next1 ){
        next=next1;
        data=d;
    }
    node(int d){
        next=nullptr;
        data=d;
    }
};
node* converttoll(vector <int> &v){
    node* head=new node(v[0]);
    node* mover=head;
    for(int i=1;i<v.size();i++){
        node* temp=new node(v[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
node* intersection(node* head1, node* head2) {
    node* temp1 = head1;
    while (temp1 != nullptr) {
        node* temp2 = head2;
        while (temp2 != nullptr) {
            if (temp1 == temp2) {  // compare nodes, not next pointers
                cout << "intersecting value is " << temp1->data << endl;
                return temp1;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return nullptr;
}


void travell(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }

}
int main() {
    vector<int> arr1 = {3,0};
    vector<int> arr2 = {9,8};

    node* head1 = converttoll(arr1);
    node* head2 = converttoll(arr2);

    // Common part
    vector<int> common = {6,7};
    node* commonHead = converttoll(common);

    // Attach common part to list1
    node* temp = head1;
    while (temp->next) temp = temp->next;
    temp->next = commonHead;

    // Attach common part to list2
    temp = head2;
    while (temp->next) temp = temp->next;
    temp->next = commonHead;

    node* inter = intersection(head1, head2);
    travell(inter);
}


/*
node* intersection(node* head1,node* head2){
    node* temp1=head1;
    int inter;
    while(temp1!=nullptr){
        node* temp2=head2;
        while(temp2!=nullptr){
        if(temp1==temp2){
            inter=temp1->data;
            cout<<"intersecting value is "<<inter<<endl;
            return temp1->next;
        }
        temp2=temp2->next;}
        temp1=temp1->next;
    }
    return NULL;

}
    
node* intersectionmm(node *A, node *B) {
    node* firstCurrNode = A;
	while (firstCurrNode != NULL) {
		node* secondCurrNode = B;
		while (secondCurrNode != NULL) {
			if (firstCurrNode == secondCurrNode) {
                cout<<firstCurrNode->data;
				return firstCurrNode;
			}
			secondCurrNode = secondCurrNode->next;
		}
		firstCurrNode = firstCurrNode->next;
	}
	return NULL;
}
*/