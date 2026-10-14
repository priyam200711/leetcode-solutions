class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        int n=secret.size();
        vector<int>a;
        unordered_map<int,int>b;
        for(int i=0;i<n;i++){
       if(secret[i]==guess[i])y++;
       else{
       a.push_back(secret[i]);
        b[guess[i]]++;
       }
        }
        for(auto it:a){
            if(b.find(it)!=b.end()){
                x++;
                b[it]--;
                if(b[it]==0)b.erase(it);
            }
        }
        string ans="";
        ans+=to_string(y);
        ans+='A';
        ans+=to_string(x);
        ans+='B';
        return ans;
    }
};