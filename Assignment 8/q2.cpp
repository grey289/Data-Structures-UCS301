#include <iostream>
#include <vector>
using namespace std;
class bst{
    public:
    int val;
    bst* left;
    bst* right;
    bst(int data){
        val=data;
        left=right=NULL;
    }
    bst* searcheriterative(bst* head, int key) {
    bst* current = head;
    while (current != NULL) {
        if (current->val == key) {
            return current; // Found it
        }
        if (key < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL; // Not found
}
    bst* searcherrec(bst* head,int key){
        if(head==NULL)return NULL;
        if(head->val==key) return head;
        else if(head->val<key) return searcherrec(head->right,key);
        else return searcherrec(head->left,key);
        
    }
    bst* minele(bst* head){
        if(head==NULL) return NULL;
        while(head->left!=NULL) head=head->left;
        return head;
    }
    bst* maxele(bst* head){
        if(head==NULL) return NULL;
        while(head->right!=NULL) head=head->right;
        return head;
    }


  bool prerec(pair<bst*,bst*>& ae, bst* head, bst* ele) {
    if (head == NULL) {
        return false; // Not found in this branch
    }

    // 1. Traverse left. If found, propagate 'true' up.
    if (prerec(ae, head->left, ele)) {
        return true; 
    }

    // 2. Visit the current node
    if (ae.second == NULL) {
        ae.second = head;
    } else {
        ae.first = ae.second;
        ae.second = head;
    }

    // 3. Check if we just processed the target element
    if (ae.second == ele) {
        return true; // Found! Signal to stop.
    }

    // 4. Traverse right. Return its result.
    return prerec(ae, head->right, ele);
}

// Your main function is correct, but it must call the fixed helper
bst* predec(bst* head, bst* ele) {
    // These edge cases are correct (assuming minele() is correct)
    if (ele == minele(head)) return NULL; 
    if (head == NULL) return NULL;       

    pair<bst*, bst*> ae;
    ae.first = ae.second = NULL;
    
    prerec(ae, head, ele); // Call the fixed helper
    
    return ae.first;
}


bst* successor(bst* head,bst* ele){
    if(ele->right!=NULL) return minele(ele->right);

    bst* succ=NULL;
    while(1){
        if(head->val<ele->val) head=head->right;
        else if(head->val>ele->val){
            succ=head;
            head=head->left;
        }else break;
    }
    return succ;
}
};
int main()
{
    
    return 0; 
}