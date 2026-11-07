class Solution {
public:
    int getMinFactor(int value) {
        for (int p = 2; p <= value / p; p++) {
            if (value % p == 0) {
                return p;
            }
        }
        return value;
    }
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)return -1;
       if(value%2==0){
         long long temp=value;
        temp-=2*index;
        if(temp<=0)return -1;
        return 1LL * value + (n - index - 1LL) * 2;
        
       }
      long long r=getMinFactor(value);
      
       long long z=value;
       z=value-r-2*(index-1);
        if(z<=0)return -1;
        if(n-1==index)return value;
       return 1LL * value + r + 1LL * (n - index - 2) * 2;
        
    }
};