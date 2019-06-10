class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i, ind;
        vector<int> ans;
        for (i = 0; i < nums.size(); i++) {
            ind = abs(nums[i]) - 1;
            nums[ind] = nums[ind] > 0 ? -nums[ind] : nums[ind];
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                ans.push_back(i+1);
        }
        return ans;
    }
};
