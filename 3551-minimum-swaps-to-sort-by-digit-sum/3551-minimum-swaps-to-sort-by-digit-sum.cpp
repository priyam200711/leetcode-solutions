class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            int val=nums[i];
            int sum=0;
            while(val){
              sum+=val%10;
              val/=10;  
            }
            v.push_back({sum,nums[i]});
        }
         sort(v.begin(),v.end());
      
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[v[i].second]=i;
        }
       
         int i=0;
         int ans=0;
         while(i<n){
            int val=nums[i];
            int pos=mp[val];
            if(i==pos){
                i++;
            }
            else {
                swap(nums[i],nums[pos]);
                ans++;
            }

         }
        
        return ans;
    }
};