class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;  // Every single-element subarray is valid.

        for (int i = 0; i < n; i++) {
            unordered_map<int, pair<int, int>> mp;
            mp.reserve(n - i);

            int distinct = 0;
            int bad = 0;

            for (int j = i; j < n; j++) {
                int len = j - i + 1;

                // A valid staircase of k distinct values
                // must have length k * (k + 1) / 2.
                int k = distinct;
                if (len > 1 && len != k * (k + 1) / 2) {
                    // Continue updating frequencies, but only
                    // validate when the length is triangular.
                }

                auto it = mp.find(nums[j]);

                if (it == mp.end()) {
                    distinct++;
                    mp.emplace(nums[j], make_pair(distinct, 1));

                    if (distinct != 1)
                        bad++;
                } else {
                    int rank = it->second.first;
                    int freq = it->second.second;

                    if (freq == rank)
                        bad++;

                    it->second.second++;

                    if (it->second.second == rank)
                        bad--;
                }

                // Check only possible staircase lengths.
                int d = distinct;
                if (len == d * (d + 1) / 2 && bad == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};