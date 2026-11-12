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
    int help(TreeNode* root,bool f,map<pair<TreeNode*,bool>,int>&mp){
        if(root==NULL)return 0;
        if(mp.find({root,f})!=mp.end())return mp[{root,f}];
        int not_take=help(root->left,true,mp)+help(root->right,true,mp);
        int take=INT_MIN;
        if(f==true){
             take=root->val+help(root->left,false,mp)+help(root->right,false,mp);
        } 
        return mp[{root,f}]= max(take,not_take);
    }
    int rob(TreeNode* root) {
       map<pair<TreeNode*,bool>,int>mp;
        return help(root,true,mp);
    }
};