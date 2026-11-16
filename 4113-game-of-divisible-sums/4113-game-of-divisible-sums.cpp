class Solution {
public:
     long long help(vector<int>&nums,int idx,vector<long long>&dp){
        if(idx==nums.size()-1)return nums[idx];
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        long long one=nums[idx]+(nums[idx]%3?help(nums,idx+1,dp):-help(nums,idx+1,dp));
        long long two=nums[idx]+nums[idx+1]+((nums[idx]+nums[idx+1])%3?help(nums,idx+2,dp):-help(nums,idx+2,dp));
        return dp[idx]=max(one,two);
     }
    long long maxDifference(vector<int>& nums) {
          int n=nums.size();
        vector<long long>dp(n,-1);
        return help(nums,0,dp);
    }
};