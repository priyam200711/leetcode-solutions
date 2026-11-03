class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=nums[0];
        for(int i=0;i<n;i++){
            mn=max(nums[i],mn);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(mn-nums[i]);
        }
        return ans;
    }
};