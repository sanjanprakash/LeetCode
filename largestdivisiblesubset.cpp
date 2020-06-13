class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i, j, n = nums.size();
        int max_idx = 0, curr;
        vector<int> dp(n, 1), end_idx(n, -1);
        vector<int> ans;
        
        if (n) {
            sort(nums.begin(), nums.end());

            for (i = 1; i < n; i++) {
                for (j = 0; j < i; j++) {
                    if (nums[i]%nums[j] == 0 && dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        end_idx[i] = j;
                    }
                }
                if (dp[i] > dp[max_idx])
                    max_idx = i;
            }

            curr = max_idx;
            while (curr >= 0) {
                ans.push_back(nums[curr]);
                curr = end_idx[curr];
            }
        }
        
        return ans;
    }
};
