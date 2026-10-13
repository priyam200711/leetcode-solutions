class Solution {
public:
    void help(vector<vector<int>>&ans,vector<int>&v,int i,int & n,int & k){
        if(i>n+1)return;
        if(v.size()>=k){
         if(v.size()==k) ans.push_back(v);
        return;
        }
         v.push_back(i);
        help(ans,v,i+1,n,k);
         v.pop_back();
        help(ans,v,i+1,n,k);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        help(ans,v,1,n,k);
        return ans;
    }
};