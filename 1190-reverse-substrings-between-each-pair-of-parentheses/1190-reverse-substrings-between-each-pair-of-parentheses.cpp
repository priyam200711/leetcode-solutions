class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        int i=0;
        while(i<n){
            if(s[i]!=')')st.push(s[i]);
            else{
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
               for(auto ch:temp)st.push(ch);
            }
            i++;
        }
        string ans="";
       while(!st.empty()){
           ans+=st.top();
           st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};