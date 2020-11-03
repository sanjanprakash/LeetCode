class Solution {
public:
    int maxPower(string s) {
        int i = 1, n = s.length();
        int cur = 1, ans = INT_MIN;
        while (i < n) {
            if (s[i] == s[i-1])
                cur++;
            else {
                ans = max(ans, cur);
                cur = 1;
            }
            i++;
        }
        return max(cur, ans);
    }
};
