class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, r = nums.size() - 1;
        int tmp;
        while (i <= r) {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 0) {
                tmp = nums[i];
                nums[i] = nums[l];
                nums[l] = tmp;
                l++;
                i++;
            }
            else {
                tmp = nums[i];
                nums[i] = nums[r];
                nums[r] = tmp;
                r--;
            }
        }
    }
};
