class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        int idx=0;
        int x=k;
        string temp="";
        while(s.size()>k){
            int sum=0;
            while(x-- && idx<s.size()){
                
                 sum+=s[idx]-'0';
                  idx++;
            }
            x=k;
            temp+=to_string(sum);
            if(idx==s.size()){
                s=temp;
                temp="";
                idx=0;
            }
        }
        return s;
    }
};