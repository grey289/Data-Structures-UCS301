#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode* up;
    ListNode* down;
    ListNode(int val1){
        val=val1;
        next=nullptr;
        prev=nullptr;
        down=nullptr;
        up=nullptr;

    }

};
ListNode* dmatrix(vector<vector<int>> matrix){
    ListNode *head=new ListNode(matrix[0][0]);
    //assuming a square matrix
    ListNode* back=head;
    for(int i=1;i<matrix.size();i++){
        ListNode* temp=new ListNode(matrix[0][i]);
        temp->prev=back;
        back->next=temp;
        back=temp;
    }
        ListNode* upperhead=head;

    for(int i=1;i<matrix.size();i++){
        ListNode* back=NULL;

        for(int j=0;j<matrix.size();j++){
            ListNode* temp=new ListNode(matrix[i][j]);
                temp->up=upperhead;
                upperhead->down=temp;   
                if(j!=matrix.size()-1)upperhead=upperhead->next; 
                temp->prev=back;
                if(back!=NULL) back->next=temp;
                back=temp;
                if(j==matrix.size()-1){
                    upperhead=upperhead->down;
                    while(upperhead->prev!=NULL) upperhead=upperhead->prev;
                }        
        }

    }
    
    return head;

}
int main()
{
    
    return 0; 
}