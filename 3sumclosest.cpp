class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int dif = INT_MAX, s;
        int n = nums.size(), ans;
        int i, l, r;
        for (i = 0; i < n - 2; i++) {
            l = i + 1;
            r = n - 1;
            while (l < r) {
                s = nums[i] + nums[l] + nums[r];
                if (abs(s - target) < dif) {
                    dif = abs(s - target);
                    ans = s;
                }
                if (s < target)
                    l++;
                else if (s > target)
                    r--;
                else
                    return s;
            }
        }
        return ans;
    }
};
