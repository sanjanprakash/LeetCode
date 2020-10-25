class Solution {
public:
    bool winnerSquareGame(int n) {
        int i, j;
        vector<bool> dp(n+1, false);
        for (i = 0; i <= n; i++) {
            if (!dp[i]) {
                for (j = 1; i + j*j <= n; j++)
                    dp[i+j*j] = true;
            }
        }
        return dp[n];
    }
};
