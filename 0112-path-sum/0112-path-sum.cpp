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
    bool help(TreeNode* root, int &ts,int sum){
        if(root->left==NULL && root->right==NULL){
            if(ts==sum)return true;
            return false;
        }
        bool a=false, b=false;
        if(root->left)a=help(root->left,ts,sum+ root->left->val);
        if(root->right)b=help(root->right,ts,sum+ root->right->val);
        return a||b;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        return help(root,targetSum,root->val);
    }
};