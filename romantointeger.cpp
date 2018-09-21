class Solution {
public:
    int romanToInt(string s) {
        int i;
        int ans = 0;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == 'M') {
                if (s[i - 1] == 'C' && i > 0)
                    ans += 800;
                else
                    ans += 1000;
            }
            if (s[i] == 'D') {
                if (s[i - 1] == 'C' && i > 0)
                    ans += 300;
                else
                    ans += 500;
            }
            if (s[i] == 'C') {
                if (s[i - 1] == 'X' && i > 0)
                    ans += 80;
                else
                    ans += 100;
            }
            if (s[i] == 'L') {
                if (s[i - 1] == 'X' && i > 0)
                    ans += 30;
                else
                    ans += 50;
            }
            if (s[i] == 'X') {
                if (s[i - 1] == 'I' && i > 0)
                    ans += 8;
                else
                    ans += 10;
            }
            if (s[i] == 'V') {
                if (s[i - 1] == 'I' && i > 0)
                    ans += 3;
                else
                    ans += 5;
            }
            if (s[i] == 'I')
                ans++;
        }
        return ans;
    }
};
