class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string str=s;

        sort(str.begin(),str.end());
        cout<<s<<endl;
        cout<<str<<endl;
        if(n==2 && s!=str)return -1;
          if(str==s)return 0;
        if(str[0]==s[n-1] && str[n-1]==s[0] && str[n-1]!=str[n-2] && str[0]!=str[1])return 3;
        if(str[0]==s[0] || str[n-1]==s[n-1])return 1;
      
        return 2;
       

    }
};