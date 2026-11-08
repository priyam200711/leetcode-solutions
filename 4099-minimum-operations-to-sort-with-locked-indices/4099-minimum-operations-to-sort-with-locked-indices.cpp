class Solution {
public:
    long long countSwaps(vector<int>& arr,int s,int e) {
    long long cnt = 0;
    for(int i = s; i <= e; i++) {
        for(int j = i + 1; j <= e; j++) {
            if(arr[i] > arr[j]) {
                cnt++;
            }
        }
    }

    return cnt;
}
    int minOperations(vector<int>& nums, vector<int>& locked, int p) {
        int n=nums.size();
        int k=p;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1 && locked[i]==1){
                if(k>0){
                    locked[i]=0;
                    k--;
                }
                else return -1;
            }
        }
      
      for(int i=0;i<n;i++){
        if(nums[i]!=i+1 && nums[i]>i+1 ){
            int val=nums[i];
            for(int j=i+1;j<=nums[i]-1;j++){
                if(locked[j]==1){
                      if(k>0){
                    locked[j]=0;
                    k--;
                }
                else return -1;
                }
            }
        }
      }
        
     int s=0;
     long long ans=0;
     for(int i=0;i<n;i++){
       if(locked[i]==1){
        ans+=countSwaps(nums,s,i);

        s=i+1;
       }
     }
     ans+=countSwaps(nums,s,n-1);
     
     return ans+p-k;
    }
};