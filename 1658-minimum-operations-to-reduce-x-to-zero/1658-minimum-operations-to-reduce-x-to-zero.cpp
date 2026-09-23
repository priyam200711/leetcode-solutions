class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>suf(n);
        int pref=nums[n-1];
        suf[0]=nums[0];
        if(suf[0]==x)return 1;
       
          if(pref==x)return 1;
        int ans=1e9;
        unordered_map<int,int>mp;
        mp[pref]=n-1;
        for(int i=1;i<n;i++){
            suf[i]=suf[i-1]+nums[i];
            if(suf[i]==x)ans=min(ans,i+1);
            }
        for(int i=n-2;i>=0;i--){
            pref+=+nums[i];
            mp[pref]=i;
               if(pref==x)ans=min(ans,n-i);
            }
        
     
        for(int i=0;i<n;i++){
            int rem=x-suf[i];
            if(rem<0)continue;
            if(mp.find(rem)!=mp.end()){
                int val=mp[rem];
                if(val<=i)continue;
                ans=min(ans,i+n-val+1);
            }
        }
       if(ans==1e9)return -1;
       return ans;
    }
};