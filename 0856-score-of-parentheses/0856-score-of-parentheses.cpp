class Solution {
public:
    int scoreOfParentheses(string s) {
     int n=s.size();
     int d=1;
     int ans=0;
     for(int i=1;i<n;i++){
           if(s[i]=='(')d++;
           else{
            d--;
            if(s[i-1]=='(')ans+=(1<<d);
           }
     }
     return ans;
    }
};