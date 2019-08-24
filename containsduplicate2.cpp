class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i, n = nums.size();
        unordered_map<int,int> ids;
        for (i = 0; i < n; i++) {
            if (ids[nums[i]] && i-ids[nums[i]]+1 <= k)
                return true;
            ids[nums[i]] = i+1;
        }
        return false;
    }
};
