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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
          TreeNode * x=new TreeNode(val);
          if(root==NULL)return x;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            TreeNode* node=q.front();
            temp=node;
            q.pop();
            if(node->val > val && node->left){
                q.push(node->left);
            }
            if(node->val<val && node->right){
                q.push(node->right);
            }
            
        }
      
        if(temp->val>val)temp->left=x;
        else temp->right=x;
        return root;
    }
};