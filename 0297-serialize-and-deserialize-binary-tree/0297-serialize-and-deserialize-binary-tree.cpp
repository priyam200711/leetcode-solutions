/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        queue<TreeNode*>q;
        if(root==NULL)return  str;
        q.push(root);
         str+=to_string(root->val);
        while(!q.empty()){
          TreeNode * temp=q.front();
          q.pop();
          
          if(temp->left){
            str=str+"."+to_string(temp->left->val);
            q.push(temp->left);
          }
          else{
            str+=".N";
          }
          if(temp->right){
            str=str+"."+to_string(temp->right->val);
            q.push(temp->right);
          }
          else{
            str+=".N";
          }
        }
        cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*>q;
        string s="";
        if(data=="")return NULL;
        int n=data.size();
        int i=0;
        while(data[i]!='.' && i<n){
            s+=data[i];
            i++;
        }
        i++;
        int v=stoi(s);
        TreeNode* node=new TreeNode(v);
        q.push(node);
        while(!q.empty()){
          TreeNode* temp=q.front();
          q.pop();
           if(data[i]=='N'){
            temp->left=NULL;
            i+=2;
            }
           else{
            s="";
             while(data[i]!='.' && i<n){
            s+=data[i];
            i++;
        }
        i++;
        int val=stoi(s);
        TreeNode* x=new TreeNode(val);
        temp->left=x;
        q.push(x);
           }
         if(data[i]=='N'){
            temp->right=NULL;
            i+=2;
            }
           else{
            s="";
             while(data[i]!='.' && i<n){
            s+=data[i];
            i++;
        }
        i++;
        int val=stoi(s);
        TreeNode* x=new TreeNode(val);
        temp->right=x;
        q.push(x);
           }
   
        }

        return node; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));