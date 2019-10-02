class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), p = s3.length();
        int i, j;
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        if (m+n == p) {
            for (i = 0; i <= m; i++) {
                for (j = 0; j <= n; j++) {
                    if (i == 0 && j == 0)
                        dp[i][j] = true;
                    else if (!i) {
                        if (s2[j-1] == s3[j-1]) 
                            dp[i][j] = dp[i][j-1];
                    }
                    else if (!j) {
                        if (s1[i-1] == s3[i-1])
                            dp[i][j] = dp[i-1][j];
                    }
                    else if (s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1])
                        dp[i][j] = dp[i-1][j];
                    else if (s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1])
                        dp[i][j] = dp[i][j-1];
                    else if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
