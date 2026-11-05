class Solution {
public:
    vector<long long> help(vector<int>& nums, int k) {
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;
    vector<long long> ans;

    auto balance = [&]() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            long long x = *it;

            low.erase(it);
            sumLow -= x;

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            long long x = *it;

            high.erase(it);
            sumHigh -= x;

            low.insert(x);
            sumLow += x;
        }
    };

    auto add = [&](long long x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }
        balance();
    };

    auto remove = [&](long long x) {
        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= x;
        } else {
            it = high.find(x);
            high.erase(it);
            sumHigh -= x;
        }
        balance();
    };

    if (k <= 0 || k > nums.size()) return ans;

    for (int i = 0; i < nums.size(); i++) {
        add(nums[i]);

        if (i >= k) {
            remove(nums[i - k]);
        }

        if (i >= k - 1) {
            long long median = *low.rbegin();

            long long cost = median * low.size() - sumLow
                           + sumHigh - median * high.size();

            ans.push_back(cost);
        }
    }

    return ans;
}
    long long help2(vector<long long>& v, int i, int k, int& x,
                vector<vector<long long>>& dp) {

    if (k == 0) return 0;
    if (i >= v.size()) return LLONG_MAX;

    if (dp[i][k] != -1) return dp[i][k];

    long long take = v[i];

    if (k > 1) {
        long long temp = help2(v, i + x, k - 1, x, dp);

        if (temp == LLONG_MAX)
            take = LLONG_MAX;
        else
            take += temp;
    }

    long long not_take = help2(v, i + 1, k, x, dp);

    return dp[i][k] = min(take, not_take);
}
    long long minOperations(vector<int>& nums, int x, int k) {
       vector<long long>v=help(nums,x);
       int n=v.size();
        vector<vector<long long>>dp(n,vector<long long>(k+1,-1));
   
       return help2(v,0,k,x,dp);

    }
};