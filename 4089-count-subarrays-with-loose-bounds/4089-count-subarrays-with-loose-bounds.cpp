class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0,temp=0;
        long long  c=0;
        int n=nums.size();
        for(int i=0;i<n;i++ ){
            if(nums[i]>=minK && nums[i]<=maxK){
               c++;
               temp+=c;
            }
            else {
                ans+=temp;
                c=0;
                temp=0;
            }
        }
         ans+=temp;
        return ans;
    }
};