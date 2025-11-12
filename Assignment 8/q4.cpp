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
     bool inorder(TreeNode* root,int & ele){
    if(root==NULL) return true ;
    bool lhs=inorder(root->left,ele);
    if(lhs==false) return false;
    if(ele!=-99){
        if(ele>=root->val) return false;
    }
    ele=root->val;
    return inorder(root->right,ele);
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        int ele=-99;
        return inorder(root,ele);
    }
};
int main()
{
    
    return 0; 
}