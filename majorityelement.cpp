class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, n = nums.size();
        int ans = INT_MAX, count = 0;
        for (i = 0; i < n; i++) {
            if (count == 0)
                ans = nums[i];
            count += ans == nums[i] ? 1 : -1;
        }
        return ans;
    }
};
