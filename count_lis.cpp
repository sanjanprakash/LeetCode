class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int i,j,n = nums.size();
        int greatest = 0, ans = 0;
        vector<int> dp(n+1,1), count(n+1,1);
        if (n) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= i; j++) {
                    if (nums[j-1] < nums[i-1]) {
                        if (dp[i] < dp[j]+1) {
                            dp[i] = dp[j] + 1;
                            count[i] = count[j];
                        }
                        else if (dp[i] == dp[j]+1)
                            count[i] += count[j];
                    }
                }
                if (greatest < dp[i]) {
                    greatest = dp[i];
                    ans = count[i];
                }
                else if (greatest == dp[i])
                    ans += count[i];
            }
        }
        return ans;
    }
};
