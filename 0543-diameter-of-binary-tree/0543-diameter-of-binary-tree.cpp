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
    int help(TreeNode* root,int &d){
        if(root==NULL)return 0;
        int ld=help(root->left,d);
        int rd=help(root->right,d);
        d=max(ld+rd,d);
        return max(rd,ld)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        help(root,d);
        return d;

    }
};