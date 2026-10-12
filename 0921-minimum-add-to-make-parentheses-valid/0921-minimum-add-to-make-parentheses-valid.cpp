class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
           if(s[i]=='('){
            st.push(1);
           }
           else{
            if(st.empty())ans++;
            else st.pop();
           }
        }
        ans+=st.size();
        return ans;
    }
};