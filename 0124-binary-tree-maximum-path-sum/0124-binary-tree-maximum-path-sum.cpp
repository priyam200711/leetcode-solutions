/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     TreeNode* copy(TreeNode* root){
        if(root==NULL)return NULL;
        TreeNode* newNode=new TreeNode(root->val);
        if(root->left)newNode->left=copy(root->left);
        if(root->right)newNode->right=copy(root->right);
        return newNode;
             }
       void help(TreeNode * root){
        if(root==NULL)return;
        help(root->left);
        help(root->right);
        int a=0, b=0;
        if(root->left)a=root->left->val;
        if(root->right)b=root->right->val;
        root->val=max({root->val,root->val+a,root->val+b});
       }      
       void post(TreeNode* root){
        if(root==NULL)return ;
        post(root->left);
        post(root->right);
        cout<<root->val<<" ";
       }
    void check(TreeNode * root,TreeNode* prev,int& ans){
     if(root==NULL)return;
     int a=0,b=0,c=0;
     if(prev->left)a=prev->left->val;
     if(prev->right)b=prev->right->val;
     c=root->val;
     ans=max({ans,c+a+b,c+a,c+b,c});
     check(root->left,prev->left,ans);
     check(root->right,prev->right,ans);
    }
    int maxPathSum(TreeNode* root) {
        TreeNode *prev=copy(root);
        help(prev);
        post(root);
        cout<<endl;
        post(prev);
        int ans=root->val;
        check(root,prev,ans);
        return ans;
    }
};