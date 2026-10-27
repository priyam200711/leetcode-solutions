class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string> ans;
       string str=".";
     for(int i=1;i<n;i++)str.push_back('#');
     for(int i=0;i<m-1;i++)ans.push_back(str);
     string ztr="";
     for(int i=0;i<n;i++)ztr.push_back('.');
     ans.push_back(ztr); 
   
    return ans;
}
};