class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i, n = cost.size();
        vector<int> dp(n+1,0);
        cost.insert(cost.begin(),0);
        dp[n] = cost[n];
        dp[n-1] = cost[n-1];
        for (i = n-2; i >= 0; i--)
            dp[i] = min(dp[i+1],dp[i+2]) + cost[i];
        return dp[0];
    }
};
