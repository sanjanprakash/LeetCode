class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, n = nums.size();
        int sum = 0;
        for (i = 0; i < n; i++)
            sum += nums[i];
        return n*(n+1)/2 - sum;
    }
};
