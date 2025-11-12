#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val=data;
        left=right=NULL;
    }
    int height(TreeNode* root,int cnt=0){
        if(root==NULL) return cnt;
        int lhs=height(root->left,cnt+1);
        int rhs=height(root->right,cnt+1);
        return max(lhs,rhs);
    }
    int mindepth(TreeNode* root,int cnt=0){
        if(root==NULL) return cnt;
        int lhs=height(root->left,cnt+1);
        int rhs=height(root->right,cnt+1);
        return min(lhs,rhs);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key) return deleter(root);
        TreeNode* node=root;
        while(node!=NULL){
           if(node->val>key){
            if(node->left!=NULL && node->left->val==key){
                node->left=deleter(node->left);
                break;
            }else node=node->left;
           } else{
            if(node->right!=NULL && node->right->val==key){
                node->right=deleter(node->right);
                break;
            }else node=node->right;
           }
        }
        return root;
    }
    TreeNode* deleter(TreeNode* node){
        if(node->left==NULL) return node->right;
        else if(node->right==NULL) return node->left;
        else{
            TreeNode* rightchild=node->right;
            TreeNode* lastright=findlastright(node->left);
            lastright->right=rightchild;
            return node->left;
        }
    }
    TreeNode* findlastright(TreeNode* node){
        if(node->right==NULL) return node;
        return findlastright(node->right);
    }
     TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* head=root;
        TreeNode * ins= new TreeNode(val);
        if(root==NULL) return ins;
        TreeNode * prev=NULL;
        while(root!=NULL){
            prev=root;
            root=(val<root->val)? root->left: root->right;
        }
        if (val < prev->val) {
                prev->left = ins;
        } else {
            prev->right = ins;
        }
    
        return head;
    }
    
};
int main()
{
    
    return 0; 
}