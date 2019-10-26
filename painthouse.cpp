class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int i, n = costs.size();
        int ans = 0;
        if (n) {
            vector<vector<int> > dp(n+1,vector<int>(3,0));
            for (i = 0; i < n; i++) {
                dp[i+1][0] = costs[i][0] + min(dp[i][1],dp[i][2]);
                dp[i+1][1] = costs[i][1] + min(dp[i][0],dp[i][2]);
                dp[i+1][2] = costs[i][2] + min(dp[i][0],dp[i][1]);
            }
            ans = min(dp[n][0],min(dp[n][1],dp[n][2]));
        }
        return ans;
    }
};
