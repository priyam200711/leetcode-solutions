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
    TreeNode* help(vector<int>& preorder, vector<int>& inorder,int i,int j,int k){
        if(i>j || k>=inorder.size() || i<0 || j>=inorder.size())return NULL;
        int x;
        TreeNode* temp=new TreeNode(preorder[k]);
        for(x=i;x<=j;x++){
            if(preorder[k]==inorder[x])break;
        }
        int leftSize = x - i;
        temp->left=help(preorder,inorder,i,x-1,k+1);
        temp->right=help(preorder,inorder,x+1,j,k+1+leftSize);
        return temp;
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j=inorder.size();
        return help(preorder,inorder,0,j-1,0);
    }
};