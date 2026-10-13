class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)if(nums[i]<0)nums[i]=-1*nums[i];
        sort(nums.begin(),nums.end());
        long long ans=0;
       int i=0,j=n-1;
       while(i<=j){
        ans+=(long long)nums[j]*nums[j];
        if(i!=j)ans-=(long long)nums[i]*nums[i];
        i++;
        j--;
       }
       return ans;
    }
};