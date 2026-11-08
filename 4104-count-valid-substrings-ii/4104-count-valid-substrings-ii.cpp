class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        int a = -1, ab = -1, abc = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b' && a != -1)
                ab = max(ab, a);
            else if (s[i] == 'c' && ab != -1)
                abc = max(abc, ab);
            ans += (i - abc);
        }
        return ans;
    }
};