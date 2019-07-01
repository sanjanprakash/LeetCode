class Solution {
public:
    int integerBreak(int n) {
        int i;
        vector<int> dp(59,0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        for (i = 7; i <= n; i++)
            dp[i] = max(dp[i-2]*2,max(dp[i-3]*3,dp[i-4]*4));
        return dp[n];
    }
};
