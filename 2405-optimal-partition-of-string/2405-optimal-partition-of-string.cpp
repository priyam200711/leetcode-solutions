class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        set<char>st;
        int ans=0;
        for(int i=0;i<n;i++){
           
           if(st.empty()|| st.find(s[i])==st.end()){
                st.insert(s[i]);
            }
            else if(st.find(s[i])!=st.end()){
                st.clear();
                ans++;
                    st.insert(s[i]);
            }
        }
         return ans+1;
    }
};