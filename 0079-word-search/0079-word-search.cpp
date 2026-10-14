class Solution {
public:
    bool help(vector<vector<char>>& board,   vector<vector<int>>&vis, string word,int idx,int i,int j){
        int n=board.size();
        int m=board[0].size();

          if(idx==word.size())return true;

          vis[i][j]=1;

          if(i+1<n && word[idx]==board[i+1][j] && vis[i+1][j]!=1){
            if(help(board,vis,word,idx+1,i+1,j))return true;
          }
            if(i-1>=0 && word[idx]==board[i-1][j] && vis[i-1][j]!=1){
            if(help(board,vis,word,idx+1,i-1,j))return true;
          }
            if(j+1<m && word[idx]==board[i][j+1] && vis[i][j+1]!=1 ){
            if(help(board,vis,word,idx+1,i,j+1))return true;
          }
            if(j-1>=0 && word[idx]==board[i][j-1] && vis[i][j-1]!=1){
            if(help(board,vis,word,idx+1,i,j-1))return true;
          }
          vis[i][j]=0;
          return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(help(board,vis,word,1,i,j))return true;
                }
            }
        }
        return false;
    }
};