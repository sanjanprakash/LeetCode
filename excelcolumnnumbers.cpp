class Solution {
public:
    int titleToNumber(string s) {
        int i;
        int ans = 0;
        for (i = 0; i < s.length(); i++) {
            ans *= 26;
            ans += s[i] - 64;
        }
        return ans;
    }
};
