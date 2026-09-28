class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=0;
        int temp=0;
        for(auto c:s){
            if(c=='('){
                temp++;
                ans=max(ans,temp);
            }
            else if(c==')')temp--;
        }
    return ans;
    }
};