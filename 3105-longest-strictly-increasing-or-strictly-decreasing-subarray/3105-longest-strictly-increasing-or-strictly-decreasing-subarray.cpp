class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=1,mn=1;
        int t1=1,t2=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                t1++;
                mn=max(mn,t2);
                t2=1;
            }
            else if(nums[i]<nums[i-1]){
                t2++;
                mx=max(mx,t1);
                t1=1;
            }
            else{
                 mn=max(mn,t2);
                 mx=max(mx,t1);
                 t2=1;
                 t1=1;
            }
        }
                  mn=max(mn,t2);
                 mx=max(mx,t1);
        return max(mn,mx);

    }
};