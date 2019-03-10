class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int i, sum = nums[0];
        for (i = 1; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] > sum)
                sum = nums[i];
            ans = max(sum,ans);
        }
        return ans;
    }
};
