class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long ans=0;
        
        long long x=min(n1,n2);
        if(c1+c2>=cb){
            ans+=(long long)x*cb;
            n1-=x;
            n2-=x;
        }
        if(n1){
             if(c1>=cb)ans+=(long long)cb*n1;
            else ans+=(long long)c1*n1;
        }
         if(n2){
             if(c2>=cb)ans+=(long long)cb*n2;
            else ans+=(long long)c2*n2;
        }
        
        
        return ans;
    }
};