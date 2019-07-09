class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int i,j;
        int n = coins.size();
        vector<vector<int> > dp(amount+1,vector<int>(n+1,0));
        for (i = 0; i <= n; i++)
            dp[0][i] = 1;
        for (i = 1; i <= amount; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j] += dp[i][j-1];
                if (coins[j-1] <= i)
                    dp[i][j] += dp[i-coins[j-1]][j];
            }
        }
        return dp[amount][n];
    }
};
