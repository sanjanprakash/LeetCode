class Solution {
public:
    int upper_bound(vector<int>& nums, int t) {
        int l = 0, r = nums.size(), m;
        while (l < r) {
            m = l + (r-l)/2;
            if (nums[m] == t)
                return m;
            if (nums[m] < t)
                l = m+1;
            else
                r = m;
        }
        if (nums[l] < t)
            return l+1;
        return l;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int i, n = nums.size();
        vector<int> dp;
        if (n) {
            dp.push_back(nums[0]);
            for (i = 1; i < n; i++) {
                if (nums[i] < dp[0])
                    dp[0] = nums[i];
                else if (nums[i] > dp[dp.size()-1])
                    dp.push_back(nums[i]);
                else
                    dp[upper_bound(dp,nums[i])] = nums[i];
            }
        }
        return dp.size();
    }
};
