class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        vector<vector<int>>v(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                v[i][j]=st.size();
            }
        }
        int ans=0;
        for(int j=0;j<n-1;j++){
            vector<int>left(27,0);
            vector<int>right(27,0);
            for(int i=0;i<=j;i++){
                left[v[i][j]]++;
            }
            for(int i=j+1;i<n;i++){
                right[v[j+1][i]]++;
            }
            for(int i=0;i<27;i++){
                ans+=left[i]*right[i];
            }
        }
        return ans;
    }
};