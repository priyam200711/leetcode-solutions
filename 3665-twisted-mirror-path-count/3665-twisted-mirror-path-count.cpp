class Solution {
public:
    const int MOD = 1e9 + 7;
    int help(vector<vector<int>>&grid ,  vector<vector<vector<int>>>&dp,int l ,int i,int j ){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1 && j==m-1){
           return 1;
        }
         if(i>=n || j>=m)return 0;
        if(dp[i][j][l]!=-1)return dp[i][j][l];
       
        int left=0,right=0;
        if(grid[i][j]==0){
          left=  help(grid,dp,0,i+1,j);
          right=  help(grid,dp,1,i,j+1);
        }
        else {
            if(l==1) left=help(grid,dp,0,i+1,j);
            else right= help(grid,dp,1,i,j+1);
        }
         return dp[i][j][l]=(left+right)%MOD;

    } 
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
         help(grid,dp,2,0,0);
        return dp[0][0][2];
    }
};