class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int r[4]={-1,0,1,0};
        int c[4]={0,1,-0,-1};
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]!=0){
                long long  sum=grid[i][j];
                grid[i][j]=0;
                 q.push({i,j});
                 while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();
                    for(int a=0;a<4;a++){
                        int nr=r[a]+x;
                        int nc=c[a]+y;
                        if(nc>=0 && nc<m && nr>=0 && nr<n && grid[nr][nc]!=0){
                            sum+=(long long )grid[nr][nc];
                            q.push({nr,nc});
                            grid[nr][nc]=0;
                        }
                    }
                 }
                 if(sum%k==0)ans++;
              }
            }
        }
        return ans;

    }
};