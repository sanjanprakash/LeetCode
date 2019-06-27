class Solution {
public:
    int helper(vector<int> arr, int l, int r) {
        if (l <= r) {
            int i;
            vector<int> dp(r-l+2,0);
            dp[1] = arr[l];
            for (i = 2; i < r-l+2; i++)
                dp[i] = max(dp[i-1],dp[i-2]+arr[l+i-1]);
            return dp[r-l+1];
        }
        return 0;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n)
            return 0;
        else if (n == 1)
            return nums[0];
        else 
            return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};
