class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum)return "";
        int x=sum/9;
        int z=sum%9;
        string ans="";
        while(x){
            x--;
            ans+='9';
            num--;
        }
        if(z!=0){
            ans+=to_string(z);
            num--;
        }
        while(num){
            ans+='0';
            num--;
        }
        return ans;
    }
};