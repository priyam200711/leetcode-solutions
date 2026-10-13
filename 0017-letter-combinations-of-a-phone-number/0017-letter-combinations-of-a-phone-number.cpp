class Solution {
public:
    void help(  vector<vector<char>>&v, string s,vector<string>&ans,string a,int i){
       if(i>=s.size()){
        ans.push_back(a);
          return ;
       } 
       int x=s[i]-'0';;
       for(auto it:v[x]){
           a+=it;
           help(v,s,ans,a,i+1);
           a.pop_back();

       }

    }
    vector<string> letterCombinations(string s) {
     vector<vector<char>> v = {
    {},
    {},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};
        vector<string>ans;
        help(v,s,ans,"",0);
        return ans;

    }
};