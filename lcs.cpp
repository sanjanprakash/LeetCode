class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i,j;
        int m = text1.length(), n = text2.length();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) 
                dp[i][j] = text1[i-1] == text2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);
        }
        return dp[m][n];
    }
};
