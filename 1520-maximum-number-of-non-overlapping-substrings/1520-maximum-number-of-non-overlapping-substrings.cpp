class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>st(26,-1),end(26,-1);
        vector<bool>isvalid(26,true);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(st[idx]==-1)st[idx]=i;
            end[idx]=i;
        }
        for(int i=0;i<26;i++){
            if(st[i]==-1)continue;
            for(int j=st[i];j<=end[i];j++){
                int idx=s[j]-'a';
                if(st[idx]<st[i]){
                    isvalid[i]=false;
                    break;
                }
                end[i]=max(end[i],end[idx]);

            }
        }
        for(int i=0;i<26;i++){
            char ch='a'+i;
            cout<<ch<<" -> "<<st[i]<<" "<<end[i]<<" "<<isvalid[i]<<endl;
        }
        int last=INT_MAX;
        vector<string >ans;
        for(int i=n-1;i>=0;i--){
            int idx=s[i]-'a';
            if(isvalid[idx]==false)continue;
             if(st[idx]==i && end[idx]<last){
                ans.push_back(s.substr(i,end[idx]-st[idx]+1));
                last=i;
             }
        }
        return ans;
    }
};