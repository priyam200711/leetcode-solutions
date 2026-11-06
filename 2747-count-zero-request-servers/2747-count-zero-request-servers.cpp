class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q) {
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });
         vector<pair<int, int>> queries;

        for (int i = 0; i < q.size(); i++) {
            queries.push_back({q[i], i});
        }
        sort(queries.begin(),queries.end());
        vector<int>ans(q.size());
        unordered_map<int,int>freq;
        int l=0,r=0,cnt=0;
        for(auto [t,idx]:queries){
            int s=t-x;
            while(r<logs.size() && logs[r][1]<=t){
                int id=logs[r][0];
                freq[id]++;
                if(freq[id]==1)cnt++;
                r++;
            }
            while(l<r && logs[l][1]<s){
                int id=logs[l][0];
                freq[id]--;
                if(freq[id]==0)cnt--;
                l++;
            }
            ans[idx]=n-cnt;
        }   
        return ans; 

    }
};