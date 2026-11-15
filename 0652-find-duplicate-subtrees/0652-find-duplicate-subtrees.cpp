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
    
    string help(TreeNode* root ,unordered_map<string,int>&mp,vector<TreeNode*>&v){
       if(root==NULL)return "N" ;
         string curr=to_string(root->val);
         string l=help(root->left,mp,v);
         string r=help(root->right,mp,v);
         string f=curr+','+l+','+r;
       if(mp.find(f)==mp.end()){
        mp[f]=1;
       }
       else{
        if(mp[f]==1)v.push_back(root);
        mp[f]++;
       }
       return f;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root==NULL)return {};
        unordered_map<string , int>mp;
        vector<TreeNode*>v;
        help(root,mp,v);
       
        return v;
    }
};