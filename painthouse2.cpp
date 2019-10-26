class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int i,j;
        int n = costs.size(), k, smallest;
        int ans = 0;
        if (n) {
            k = costs[0].size();
            ans = INT_MAX;
            vector<int> dp(k,0);
            vector<int> left_min(k,0), right_min(k,0);
            for (i = 0; i < n; i++) {
                for (j = 0; j < k; j++) {
                    dp[j] = costs[i][j];
                    smallest = min(left_min[j],right_min[j]);
                    if (smallest != INT_MAX)
                        dp[j] += smallest;
                }
                for (j = 0; j < k; j++) {
                    if (j == 0) {
                        left_min[j] = INT_MAX;
                        right_min[k-j-1] = INT_MAX;
                    }
                    else {
                        left_min[j] = min(left_min[j-1],dp[j-1]);
                        right_min[k-j-1] = min(right_min[k-j],dp[k-j]);
                    }
                }
            }
            for (auto &x : dp)
                ans = min(ans,x);
        }
        return ans;
    }
};
