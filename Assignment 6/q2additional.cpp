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
int converttobin(int deci){
    int binary=0;
    int arr[100];
    int cnt=0;
    int dig=0;
    while(deci){
        dig=deci%2;
        arr[cnt]=dig;
        cnt++;
        deci=deci/2;
    }
    cnt--;
    while(cnt>=0){
        binary=binary*10+arr[cnt];
        cnt--;
    }
    return binary;
}
int parity(int binary){
    int cnt=0;
    while(binary>0){
        int dig=binary%10;
        if(dig==1) cnt++;
        binary=binary/10;
    }
    return cnt;
}
//DLL
ListNode* removeEvenParityNodes(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // 1. Handle the head of the list separately.
    // Remove all nodes from the beginning with even parity.
    while (head != nullptr && parity(converttobin(head->val)) % 2 == 0) {
        ListNode* nodeToDelete = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete nodeToDelete; // Use delete in C++, not free()
    }

    // If the whole list was deleted
    if (head == nullptr) {
        return nullptr;
    }

    // 2. Traverse the rest of the list.
    // We know 'head' is safe, so we can start from it.
    ListNode* current = head;
    while (current != nullptr) {
        if (parity(converttobin(current->val)) % 2 == 0) {
            // Node needs to be deleted
            ListNode* nodeToDelete = current;
            
            // Bypass the node
            current->prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            // Move current to the next node before deleting
            current = current->next;
            delete nodeToDelete;
        } else {
            // Node is fine, just move to the next one
            current = current->next;
        }
    }
    return head;
}
//circular ll
ListNode* removeparity(ListNode* head){
    if(head==NULL) return NULL;
    ListNode* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    while(head!=nullptr && (parity(converttobin(head->val)))%2==0){
        ListNode* nodeToDelete = head;
         if (head->next == nullptr) {
            delete head;
            return nullptr;
    }
        head = head->next;
        nodeToDelete->next=nullptr;
        delete nodeToDelete;
        temp->next=head;

    }
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* prev=head;
    temp=head->next;
    while(temp!=head){
        if((parity(converttobin(temp->val)))%2==0){
            ListNode* del=temp;
            temp=temp->next;
            prev->next=temp;
            delete del;
        }else{
            prev=temp;
            temp=temp->next;
        }
    }



    return head;
}
int main()
{
    
    return 0; 
}