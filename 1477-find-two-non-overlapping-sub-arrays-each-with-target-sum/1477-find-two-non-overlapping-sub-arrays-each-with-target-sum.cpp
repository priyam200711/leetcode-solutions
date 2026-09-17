class Solution {
public:
   
    int minSumOfLengths(vector<int>& arr, int target) {
     int n=arr.size();
     int i=0,j=0;
     int currSum=0;
     vector<int>prev(n,1e9);
     int mn=1e9;
     int ans=1e9;
     while(j<n){
        currSum+=arr[j];
        while(i<j && currSum>target){
            currSum-=arr[i++];
        }
        if(currSum==target){
            int len=j-i+1;
            if(i>0 && prev[i-1]!=1e9){
                ans=min(ans,len+prev[i-1]);
            }
            mn=min(mn,len);
        }
        prev[j]=mn;
        j++;
     }
     return  ans==1e9?-1:ans;
    }
};