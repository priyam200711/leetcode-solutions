
class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        const long long MOD = 1e9 + 7;
        int n = nums1.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums1[i], nums0[i]});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a.second == 0 || b.second == 0) {
                return a.second == 0 && b.second != 0;
            }

            if (a.first != b.first) {
                return a.first > b.first;
            }

            return a.second < b.second;
        });

        long long ans = 0;

        for (auto &p : v) {
            int ones = p.first;
            int zeros = p.second;

           
            for (int i = 0; i < ones; i++) {
                ans = (ans * 2 + 1) % MOD;
            }

            
            for (int i = 0; i < zeros; i++) {
                ans = (ans * 2) % MOD;
            }
        }

        return ans;
    }
};
