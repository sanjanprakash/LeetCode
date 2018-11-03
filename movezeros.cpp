class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zeros = 0, i = 0;
        while (i < nums.size()) {
            if (nums[i] != 0) {
                non_zeros++;
                nums[non_zeros - 1] = nums[i];
            }
            i++;
        }
        for (i = non_zeros; i < nums.size(); i++)
            nums[i] = 0;
    }
};
