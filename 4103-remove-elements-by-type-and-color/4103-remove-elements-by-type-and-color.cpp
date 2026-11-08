class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& gs) {
              int n=types.size();
              int m=gs.size();
              stack<tuple<int,int,int>>st;
              for(int i=0;i<n;i++){
               if(st.empty()){
                if(gs[types[i]]!=1) st.push({types[i],colors[i],1});
               
               }
               else{
                auto [a,b,c]=st.top();
                if(a==types[i] && b==colors[i]){
                    st.push({a,b,c+1});
                    c++;
                    if(c%gs[a]==0){
                        while(--c)st.pop();
                        st.pop();
                    }
                }
                else{
                    if(gs[types[i]]!=1)st.push({types[i],colors[i],1});

                }
               }
              }

          if(st.empty())return true;
          return false;    
    }
};