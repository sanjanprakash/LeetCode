class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int count = 1;
        int i,last_unique = 0;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                count++;
                nums[count - 1] = nums[i];
            }
        }
        return count;
    }
};
