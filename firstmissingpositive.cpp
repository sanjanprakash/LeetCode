class Solution {
public:
    
    int firstMissingPositive(vector<int>& nums) {
        int i, n = nums.size();
        if (n == 0)
            return 1;
        for (i = 0; i < n; i++) {
            if (nums[i] <= 0)
                nums[i] = n+1;
        }
        for (i = 0; i < n; i++) {
            if (abs(nums[i])-1 < n && abs(nums[i])-1 >= 0)
                nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for (i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i+1;
        }
        return n+1;
    }
};
