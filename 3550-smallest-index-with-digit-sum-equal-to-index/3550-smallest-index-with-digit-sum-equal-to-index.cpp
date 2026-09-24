class Solution {
public:
    int check(int n){
        int temp=n;
        int sum=0;
        while(temp){
            sum+=temp%10;
            temp/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(check(nums[i])==i)return i;
        }
        return -1;
    }
};