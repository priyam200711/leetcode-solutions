class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
     int r[4] = {0, -1, 0, 1};
     int c[4] = {-1, 0, 1, 0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                        queue<pair<int,int>>q;
                        q.push({i,j});
                        grid[i][j]=1;
                        while(!q.empty()){
                           auto [x,y]=q.front();
                           q.pop();
                           for(int k=0;k<4;k++){
                            int nx=r[k]+x;
                            int ny=c[k]+y;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                                grid[nx][ny]=1;
                                q.push({nx,ny});
                            }
                           }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==0){
                ans++;
                        queue<pair<int,int>>q;
                        q.push({i,j});
                        grid[i][j]=1;
                        while(!q.empty()){
                           auto [x,y]=q.front();
                           q.pop();
                           for(int k=0;k<4;k++){
                            int nx=r[k]+x;
                            int ny=c[k]+y;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                                grid[nx][ny]=1;
                                q.push({nx,ny});
                            }
                           }
                        }
                    }
            }
        }
        return ans;
    }
};