class Solution {
public:
    bool help3(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int help2(string &s,int idx,int& k){
        for(int i=idx+k-1;i<s.size();i++){
               if(help3(s,idx,i))return i;
        }
        return -1;
            }
      int  help(string& s,vector<int>&dp,int idx,int& k){
        if(idx>=s.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int take=INT_MIN;
            int end = help2(s, idx, k);   // only once
    if(end != -1)
        take = 1 + help(s, dp, end + 1, k);
        int not_take=help(s,dp,idx+1,k);
        return dp[idx]=max(not_take,take);
       }     
    int maxPalindromes(string s, int k) {
       int n=s.size();
       vector<int>dp(n+1,0);
    //    int x=help(s,dp,0,k);
       for(int i=n-1;i>=0;i--){
              int take=INT_MIN;
            int end = help2(s, i, k);   
             if(end != -1)
        take = 1 + dp[end + 1];
        int not_take=dp[i+1];
        dp[i]=max(not_take,take);
       }
      return dp[0];
                
    }
};