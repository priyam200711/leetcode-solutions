class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            string s = to_string(x);

            sort(s.begin(), s.end(), greater<char>());
            int val = stoi(s);
            temp[i] = val;
        }

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {

            arr.push_back({temp[i] - nums[i], i});
        }
        long long ans = 0;
        sort(arr.begin(), arr.end());

        for (int i = n - 1; i >= 0; i--) {

            if (k > 0) {
                ans += (long long)temp[arr[i].second];
                k--;
            } else {
                ans += (long long)nums[arr[i].second];
            }
        }
        return ans;
    }
};