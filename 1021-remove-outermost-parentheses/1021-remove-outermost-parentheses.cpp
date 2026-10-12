class Solution {
public:
    string removeOuterParentheses(string s) {
        int l=0,r=0;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(l!=r)ans+='(';
                l++;
            }
            else {
                r++;
                if(l!=r)ans+=')';
            }
        }
        return ans;
    }
};