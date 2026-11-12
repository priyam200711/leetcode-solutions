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
    void help(TreeNode* root,long long& ans,long long z){
      if(root->left==NULL && root->right==NULL){
         z=z*10+root->val;
        ans+=z;
        return;
      }
      z=z*10+root->val;
      
       if(root->left) help(root->left,ans,z);
      
       if(root->right) help(root->right,ans,z);
    }
    int sumNumbers(TreeNode* root) {
     long long ans=0;
      help(root,ans,0)  ;
      return ans; 
    }
};