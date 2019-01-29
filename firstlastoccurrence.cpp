class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r) {
            mid = l + (r-l)/2;
            if (nums[mid] < target)
                l = mid+1;
            else 
                r = mid;
        }
        if (nums.size() == 0 || nums[l] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else {
            ans.push_back(l);
            r = nums.size()-1;
            while (l < r) {
                mid = (l+r)/2 + 1;
                if (nums[mid] <= target)
                    l = mid;
                else 
                    r = mid-1;
            }
            ans.push_back(r);
        }
        return ans;
    }
};
