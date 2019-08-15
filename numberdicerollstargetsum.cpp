class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int i,j,k;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for (i = 1; i <= d; i++) {
            vector<int> neo_dp(target+1,0);
            for (j = 1; j <= f; j++) {
                for (k = j; k <= target; k++) 
                    neo_dp[k] = (neo_dp[k] + dp[k-j]) % 1000000007;
            }
            dp = neo_dp;
        }
        return dp[target];
    }
};
