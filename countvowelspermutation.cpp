class Solution {
public:
    int countVowelPermutation(int n) {
        int i, mod = 1000000007;
        vector<vector<long long int> > dp(n+1,vector<long long int>(5,0));
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        for (i = 2; i <= n; i++) {
            dp[i][0] = (dp[i][0] + (((dp[i-1][1] + dp[i-1][2])%mod) + dp[i-1][4])%mod)%mod;
            dp[i][1] = (dp[i][1] + (dp[i-1][0] + dp[i-1][2])%mod)%mod;
            dp[i][2] = (dp[i][2] + (dp[i-1][1] + dp[i-1][3])%mod)%mod;
            dp[i][3] = (dp[i][3] + dp[i-1][2])%mod;
            dp[i][4] = (dp[i][4] + (dp[i-1][2] + dp[i-1][3])%mod)%mod;
        }
        return (((((((dp[n][0]+dp[n][1])%mod)+dp[n][2])%mod)+dp[n][3])%mod)+dp[n][4])%mod;
    }
};
