class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0],nums[1]);
        int i;
        int *money = new int[n];
        money[0] = nums[0];
        money[1] = max(nums[1],money[0]);
        for (i = 2; i < n; i++) {
            money[i] = max(money[i-2]+nums[i],money[i-1]);
        }
        return money[n-1];
    }
};
