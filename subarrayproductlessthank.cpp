class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i, j;
        int n = nums.size();
        int prod, ans = 0, run_prod = 1;
        vector<int> dp(n+1,0);
        for (i = 0; i < n; i++) {
            run_prod *= nums[i];
            if (run_prod > 0 && run_prod < k) 
                dp[i+1] = dp[i]+1;
            else {
                prod = 1;
                for (j = i; j >= 0; j--) {
                    prod *= nums[j];
                    if (prod < k)
                        dp[i+1]++;
                    else
                        break;
                }
                run_prod = j == -1 ? prod : prod/nums[j];
            }
            ans += dp[i+1];
        }
        return ans;
    }
};
