#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class bt{
    public:
    int val;
    bt* left;
    bt* right;
    bt(int data){
        val=data;
        left=NULL;
        right=NULL;

    }
    void in(bt* head, vector<int> &ans){
        if(head==NULL) return;
        in(head->left,ans);
        ans.push_back(head->val);
        in(head->right,ans);
        return;

    }
    vector<int> inorder(bt *head){
        vector<int> ans;
        in(head,ans);
        return ans;
    }
    void pre(bt* head, vector<int> &ans){
        if(head==NULL) return;
        pre(head->left,ans);
        ans.push_back(head->val);
        pre(head->right,ans);
        return;

    }
    vector<int> preorder(bt *head){
        vector<int> ans;
        pre(head,ans);
        return ans;
    }
    void post(bt* head, vector<int> &ans){
        if(head==NULL) return;
        post(head->left,ans);
        ans.push_back(head->val);
        post(head->right,ans);
        return;

    }
    vector<int> postorder(bt *head){
        vector<int> ans;
        post(head,ans);
        return ans;
    }



};


int main()
{
    
    return 0; 
}