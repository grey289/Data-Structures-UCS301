#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val1){
        val=val1;
        next=nullptr;
    }

};
std::pair<ListNode*, ListNode*> splitCircularList(ListNode* head) {
    if (head == nullptr || head->next == head) {
        return {head, nullptr};
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // 1. THIS IS THE KEY: Use the standard `while` loop to find the middle.
    // This loop reliably places 'slow' at the last node of the first half.
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Adjust 'fast' for even-length lists so it's at the very last node.
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // 3. Define the heads of the two lists.
    ListNode* head1 = head;
    ListNode* head2 = slow->next; // The 2nd list starts after the 1st one ends.

    // 4. Rewire the pointers using logic similar to what you wrote!
    fast->next = head2;  // The end of the 2nd list now loops to its start.
    slow->next = head1;  // The end of the 1st list now loops to its start.

    return {head1, head2};
}
int main()
{
    
    return 0; 
}