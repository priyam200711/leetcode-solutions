class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>>child(n);
        for(int i=1;i<n;i++){
            child[parent[i]].push_back(i);
        }
        vector<int>order;
        order.push_back(0);
        for(int i=0;i<order.size();i++){
            int u=order[i];
            for(auto it:child[u]){
                order.push_back(it);
            }
        }
        vector<long long >dp(n,0);
        for(int i=n-1;i>=0;i--){
            int u=order[i];
            if(child[u].empty()){
                dp[u]=score[u];
                continue;
            }
            long long sum=0;
            long long mc=INT_MAX;
            for(auto it :child[u]){
               sum+=dp[it];
             mc=min(mc,dp[it]);
            }
            if(op[u]==1)dp[u]=score[u]+sum-mc;
            else dp[u]=score[u]+sum-min(0LL,mc);

        }
        return dp[0];
    }
};