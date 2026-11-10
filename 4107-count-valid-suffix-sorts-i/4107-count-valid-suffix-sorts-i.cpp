class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
         for(auto it:target){
            if(mp[it]==1)mp.erase(it);
            else mp[it]--;
        }
        if(mp.size()!=0)return 0;
        int idx;
        
        for( idx=0;idx<n-1;idx++){
            if(nums[idx]!=target[idx])break;
        }
        for(int i=idx;i<n-1;i++){
            if(target[i]<target[i+1])return 0;
        }
        int ans=1;
        for(int i=idx;i>0;i--){
            if(target[i]<=target[i-1])ans++;
            else break;
        }
        cout<<ans;
        return ans;
       
     
    }
};