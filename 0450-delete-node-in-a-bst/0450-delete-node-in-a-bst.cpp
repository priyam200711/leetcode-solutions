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
    TreeNode* help(TreeNode * root){
     if(!root->right)return root->left;
     else if(!root->left)return root->right;
     TreeNode* rightchild=root->right;
     TreeNode* lastright=help2(root->left);
     lastright->right=rightchild;
     return root->left;
    }
    TreeNode* help2(TreeNode* root){
        if(root->right==NULL)return root;
        return help2(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key)return help(root);
         TreeNode* dummy=root;
         while(root){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=help(root->left);
                    break;
                }
                else root=root->left;
            }
            else {
                 if(root->right && root->right->val==key){
                    root->right=help(root->right);
                    break;
                }
                else root=root->right;
            }
         }
         return dummy;

    }
};