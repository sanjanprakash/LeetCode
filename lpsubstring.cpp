class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0)
            return "";
        if (s.length() == 1)
            return s;
        int n = s.length(),i,j,k;
        int start = 0,max = 1;
        vector<vector<bool>> table(s.size(), vector<bool>(s.size(), false));
        for (i = 0; i < n; i++) {
            table[i][i] = true;
        }
        for (i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                max = 2;
            }
        }
        for (k = 3; k <= n; k++) {
            for (i = 0; i < n - k + 1; i++) {
                j = i + k - 1;
                if (table[i + 1][j - 1] == true && s[i] == s[j]) {
                    table[i][j] = true;
                    if (k > max) {
                        max = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,max);
    }
};
