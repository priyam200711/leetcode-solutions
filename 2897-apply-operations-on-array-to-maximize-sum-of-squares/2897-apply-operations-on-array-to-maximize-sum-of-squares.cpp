class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>b(30,0);
        long long ans=0,mod=1e9+7;
        for(auto it:nums)
        for(int i=0;i<30;i++)
        if(it&(1<<i))b[i]++;

        while(k){
            k--;
            long long x=0;
            for(int i=0;i<30;i++){
                if(b[i]!=0){
                 x+= 1LL << i;
                 b[i]--;
                }
            }
            ans=(ans+x*x)%mod;
        }
        return (int )ans;
    }
};