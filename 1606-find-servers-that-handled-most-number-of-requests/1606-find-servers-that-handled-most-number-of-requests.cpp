class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        vector<int>v(k,0);
      
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>wait;
        set<int>st;
       
        for(int i=0;i<k;i++){
            st.insert(i);
        }
        for(int i=0;i<n;i++){
            int t=arrival[i];
            while(!wait.empty()){
                auto [a,b]=wait.top();
                if(a<=t){
                    st.insert(b);
                    wait.pop();
                }
                else break;
            }
            if(st.empty())continue;
            if(st.count(i%k)){
                int val=i%k;
                cout<<val<<" ";
                v[val]++;
                st.erase(val);
                wait.push({t+load[i],val});
            }
            else{
               int pref = i % k;
               
            auto it = st.lower_bound(pref);
            if (it == st.end()) it = st.begin();
            int s = *it;
            st.erase(it);
            wait.push({t + load[i], s});
            cout<<s<<" ";
            v[s]++;
            }
        }
        cout<<endl;
        int mx=0;
        vector<int>ans;
        for(int i=0;i<k;i++){
            cout<<v[i]<<" ";
           mx=max(v[i],mx); 
        }
        for(int i=0;i<k;i++){
            if(v[i]==mx)ans.push_back(i);
        }
        return ans;
    }
};