#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        left=right=NULL;
        val=0;
    }
    TreeNode(int data){
        val=data;
        left=right=NULL;
    }
    bool leaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }
    void lefter(TreeNode* root, int & lefty ,TreeNode* prev){
        if(root==NULL) return ;
        if(prev!=NULL){
            if( leaf(root) && prev->left==root ) lefty=lefty+(root->val);
        }
        lefter(root->left,lefty,root);
        lefter(root->right,lefty,root);
        return;
    }
    int sumleftleaf(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        TreeNode* temp=root;
        int lefty=0;
        lefter(root,lefty,NULL);
       
        return lefty;

    }
};
int main()
{
    
    return 0; 
}