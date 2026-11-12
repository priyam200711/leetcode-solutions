class Solution {
public:
   bool help(vector<vector<int>>&adj,vector<int>&vis,int node ,int des){
    if(node==des)return true;
    vis[node]=1;
    for(auto it :adj[node]){
        if(vis[it]==0){
        if(help(adj,vis,it,des))return true;
        }
    }
    return false;
   }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>vis(n,0);
        return help(adj,vis,source,destination);

    }
};