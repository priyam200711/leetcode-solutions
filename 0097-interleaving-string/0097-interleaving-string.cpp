class Solution {
public:
    bool help(string& s1,string& s2, string& s3,  vector<vector<vector<int>>>&dp, int a,int b ,int c){
        int p=s1.size();
        int q=s2.size();
        int r=s3.size();
        if(c==r)return true;
        if(dp[a][b][c]!=-1)return dp[a][b][c];
        if(a<p && b<q && s1[a]==s3[c] && s2[b]==s3[c]){
            return dp[a][b][c]= (help(s1,s2,s3,dp,a+1,b,c+1) || help(s1,s2,s3,dp,a,b+1,c+1));
        }
        if(a<p && s1[a]==s3[c])  return dp[a][b][c]= help(s1,s2,s3,dp,a+1,b,c+1);
        if(b<q && s2[b]==s3[c])  return dp[a][b][c]=  help(s1,s2,s3,dp,a,b+1,c+1);
        return dp[a][b][c]= false;
    }
    bool isInterleave(string s1, string s2, string s3) {
         int p=s1.size();
        int q=s2.size();
        int r=s3.size();
        if(p+q !=r)return false;
        vector<vector<vector<int>>>dp(p+1,vector<vector<int>>(q+1,vector<int>(r+1,-1)));
      return help(s1,s2,s3,dp,0,0,0);
    }
};