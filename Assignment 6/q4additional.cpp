#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int val1){
        val=val1;
        next=nullptr;
        prev=nullptr;
    }

};


ListNode corrector(ListNode* head){
    head->prev=nullptr;
    ListNode* temp=head;
    ListNode* back=NULL;
    ListNode* fore=head->next;
    while(temp){
        if(temp==head){
            if(fore->prev!=temp){
                //head->next is incorrectly pointed
            }else{
                // all okay 
                back=temp;
                temp=temp->next;
                fore=fore->next;
            }
        }else if(temp->next==nullptr){       //checking tail
            if(temp->prev!=back){
                temp->prev=back;
                back=temp;
                temp=temp->next;
            }

        }else {// checking a node normal
            if(temp->prev!=back){
                temp->prev=back;
                back=temp;
                temp=fore;
                fore=fore->next;

            }else if(fore->prev!=temp){
                //incorrect temp next
            }else{
                back=temp;
                temp=fore;
                fore=fore->next;
            }
        }
    }
}
int main()
{
    
    return 0; 
}