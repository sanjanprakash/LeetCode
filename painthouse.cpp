class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int i, n = costs.size();
        int ans = 0;
        if (n) {
            vector<int> prev(3,0), dp(3,0);
            for (i = 0; i < n; i++) {
                dp[0] = costs[i][0] + min(prev[1],prev[2]);
                dp[1] = costs[i][1] + min(prev[0],prev[2]);
                dp[2] = costs[i][2] + min(prev[0],prev[1]);
                prev = dp;
            }
            ans = min(dp[0],min(dp[1],dp[2]));
        }
        return ans;
    }
};
