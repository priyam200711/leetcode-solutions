class Solution {
public:
    int gcd(int a, int b) {
    return __gcd(a, b);
}


long long lcm(int a, int b) {
    return (1LL * a / gcd(a, b)) * b;
}
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int l=nums[i];
            int h=nums[i];
           unsigned long long val=1;
          for(int j=i;j<n;j++){
             val*=( unsigned long long)nums[j];
             l=lcm(l,nums[j]);
             h=gcd(h,nums[j]);
             if(l*h==val)ans=max(j-i+1,ans);
          }
        }
        return ans;
    }
};