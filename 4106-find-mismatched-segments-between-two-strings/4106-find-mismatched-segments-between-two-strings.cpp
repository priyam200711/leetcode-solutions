class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.size();
        vector<vector<string>>ans;
        string a="";
        string b="";
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                a+=s1[i];
                b+=s2[i];
            }
            else{
                if(a.size()!=0){
                    ans.push_back({a,b});
                    a="";
                    b="";
                }
            }
        }
        if(a.size()!=0){
                    ans.push_back({a,b});
                    a="";
                    b="";
                }
        return ans;
    }
};