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
    TreeNode * help(vector<int>& inorder, vector<int>& postorder,int i ,int j,int q){
        if(i>j)return NULL;
        int x=postorder[q];

        TreeNode * root=new TreeNode(x);
        if(i==j)return root;
        int z=i;
        for(int idx=i;idx<=j;idx++){
            if(x==inorder[idx]){
                z=idx;
                break;
            }
        }
        root->left=help(inorder,postorder,i,z-1,q-(j-z)-1);
        root->right=help(inorder,postorder,z+1,j,q-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return help(inorder,postorder,0,n-1,n-1);
    }
};