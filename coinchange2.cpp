class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int i,j;
        int n = coins.size();
        vector<int>  dp(amount+1,0);
        dp[0] = 1;
        for (i = 0; i < n; i++) {
            for (j = coins[i]; j <= amount; j++) 
                dp[j] += dp[j-coins[i]];
        }
        return dp[amount];
    }
};
