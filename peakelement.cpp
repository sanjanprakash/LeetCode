class Solution {
public:
    int Peak(vector<int>& nums, int l, int r) {
        if (l +1 < r) {
            int m = (l+r)/2;
            if (nums[m] > nums[m-1] && nums[m] > nums[m+1])
                return m;
            if (nums[m] < nums[m+1])
                return Peak(nums,m+1,r);
            return Peak(nums,l,m);
        }
        if (nums[l] > nums[r])
            return l;
        return r;
    }
    
    int findPeakElement(vector<int>& nums) {
        return Peak(nums,0,nums.size()-1);        
    }
};
