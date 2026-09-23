class Solution {
public:
  vector<int>dp;
  int M=1e9+7;
    int help(int idx, vector<int>&prev){
        if(idx < 0) return 1;
        if(dp[idx]!=-1)return dp[idx];
        int total=(2*help(idx-1,prev))%M;
         if(prev[idx]!=0){
        int duplicate=help(prev[idx]-2,prev);
           total=(total-duplicate+M)%M;
         }
        
        return dp[idx]=total;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>lastseen(26,0);
        vector<int>prev(n+1);
        dp.assign(2001,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
             prev[i]=lastseen[idx];
            lastseen[idx]=i+1;
        }
        return (help(n-1,prev)-1+M)%M;

    }
};