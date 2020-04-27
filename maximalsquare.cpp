class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int i, j;
        int ans = 0;
        int m = matrix.size(), n;
        if (m) {
            n = matrix[0].size();
            vector<vector<int> > dp(m, vector<int> (n, 0));
            for (i = 0; i < n; i++) {
                if (matrix[0][i]-'0') {
                    dp[0][i] = 1;
                    ans = 1;
                }
            }
            for (i = 0; i < m; i++) {
                if (matrix[i][0]-'0') {
                    dp[i][0] = 1;
                    ans = 1;
                }
            }
            for (i = 1; i < m; i++) {
                for (j = 1; j < n; j++) {
                    if (matrix[i][j]-'0') {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        return ans*ans;
    }
};
