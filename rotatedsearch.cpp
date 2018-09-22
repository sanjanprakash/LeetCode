class Solution {
public:
    int aux(vector<int>& nums, int l, int r, int target) {
        int mid = l + (r - l)/2;
        if (l > r)
            return -1;
        if (nums[mid] == target)
            return mid;
        if (nums[0] <= nums[mid]) {
            if (target >= nums[l] && target <= nums[mid])
                return aux(nums,l,mid - 1,target);
            return aux(nums,mid + 1,r,target);
        }
        if (target >= nums[mid] && target <= nums[r])
            return aux(nums,mid + 1,r,target);
        return aux(nums,l,mid - 1,target);
    }
    
    int search(vector<int>& nums, int target) {
        return aux(nums,0,nums.size() - 1,target);
    }
};
