class Solution {
public:
    int rob(vector<int>& nums) {
        int i, n = nums.size();
        vector<int> dp(n+1,0);
        if (!n)
            return 0;
        else {
            dp[1] = nums[0];
            for (i = 2; i < n+1; i++)
                dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
            return dp[n];
        }
    }
};
