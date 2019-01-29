class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() > 1) {
            int i = nums.size()-1,j;
            int temp;
            while (i > 0 && nums[i] <= nums[i-1]) 
                i--;
            j = i;
            while (i > 0 && j < nums.size() && nums[j] > nums[i-1])
                j++;
            if (i >= 0) {
                temp = nums[i-1];
                nums[i-1] = nums[j-1];
                nums[j-1] = temp;
            }
            sort(nums.begin()+i,nums.end());
        }
    }
};
