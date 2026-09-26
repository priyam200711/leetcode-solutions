class Solution {
public:
    string evaluate(string s, vector<vector<string>>& val) {
        int n=s.size();
        unordered_map<string,string>mp;
        for(auto it:val){
            mp[it[0]]=it[1];
        }
        string ans="";
        int i=0;
        while(i<n){
            if(s[i]=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
               
                if(mp.find(temp)!=mp.end()){
                  
                     ans+=mp[temp];
                }
                else ans+='?';
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};