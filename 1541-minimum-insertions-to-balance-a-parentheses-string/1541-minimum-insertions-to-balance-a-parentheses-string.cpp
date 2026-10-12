class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
    int ans=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(1);
            }
           else if(i+1<n && s[i]==')'&& s[i+1]==')' ){
               if(!st.empty()) st.pop();
               else ans++;
               i++;
            }
           else if(s[i]==')'){
            if(st.empty())ans+=2;
            else {
                ans++;
                st.pop();
            }
           }
        }
        while(!st.empty()){
            ans+=2;
            st.pop();
        }
        return ans;
    }
};