
class Solution {
public:
    int count(string &s, int st, int end) {
        int len = end - st + 1;
        int ans = INT_MAX;

        for (int d = 1; d < len; d++) {
            if (len % d != 0) continue;

            int changes = 0;

            for (int i = 0; i < d; i++) {
                int l = st + i;
                int r = st + i + ((len - 1 - i) / d) * d;

                while (l < r) {
                    if (s[l] != s[r]) changes++;

                    l += d;
                    r -= d;
                }
            }

            ans = min(ans, changes);
        }

        return ans;
    }

    int help(string &s, vector<vector<int>>& dp, int idx, int k) {

        if (k == 0)
            return idx == s.size() ? 0 : 1e4;

        if (idx >= s.size()) return 1e4;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int ans = 1e4;

        for (int i = idx + 1; i < s.size(); i++) {
            int val = count(s, idx, i);

            ans = min(ans, (val + help(s, dp, i + 1, k - 1)));
        }

        return dp[idx][k] = ans;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return help(s, dp, 0, k);
    }
};
