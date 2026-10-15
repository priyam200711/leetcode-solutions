class Solution {
public:
    void solve(vector<int>& nums, vector<int>& freq,
               vector<int>& ds, vector<vector<int>>& ans) {

        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (freq[i] == 0) {
                if (i > 0 && nums[i] == nums[i - 1] && freq[i - 1] == 0)
                    continue;

                ds.push_back(nums[i]);
                freq[i] = 1;

                solve(nums, freq, ds, ans);

                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);

        solve(nums, freq, ds, ans);
        return ans;
    }
};