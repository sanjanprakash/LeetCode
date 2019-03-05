class Solution {
public:   
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int mid;
        while (l < r) {
            mid = l + (r-l)/2;
            if (nums[mid] == target)
                return true;
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid;
                else
                    l = mid+1;
            }
            else if (nums[l] > nums[mid]) {
                if (nums[mid] < target && target < nums[l])
                    l = mid+1;
                else
                    r = mid;
            }
            else
                l++;
        }
        return false;
    }    
};
