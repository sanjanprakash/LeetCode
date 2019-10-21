class Solution {
public:
    int numDistinct(string s, string t) {
        int i,j;
        int m = s.length(), n = t.length(); 
        vector<vector<long long int> > dp(n+1,vector<long long int>(m+1,0));
        for (i = 0; i <= m; i++)
            dp[0][i] = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (t[i] == s[j])
                    dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
                else
                    dp[i+1][j+1] = dp[i+1][j];
            }
        }
        return dp[n][m];
    }
};
