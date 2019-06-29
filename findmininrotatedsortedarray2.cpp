class Solution {
public:    
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m;
        while (l < r) {
            m = l + (r-l)/2;
            if (nums[m] < nums[r])
                r = m;
            else if (nums[m] > nums[r])
                l = m+1;
            else
                r--;
        }
        return nums[l];
    }
};
