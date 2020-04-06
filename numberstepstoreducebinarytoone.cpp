class Solution {
public:
    int numSteps(string s) {
        int i = s.length()-1, carry = 0;
        int ans = 0;
        while (i > 0) {
            if (s[i]-'0'+carry == 1) {
                carry = 1;
                ans++;
            }
            ans++;
            i--;
        }
        ans += carry;
        return ans;
    }
};
