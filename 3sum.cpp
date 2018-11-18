class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();
        if (n == 0)
            return ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int i, l, r;
        for (i = 0; i < n - 2; i++) {
            if ((i > 0 && nums[i] != nums[i - 1]) || i == 0) {
                l = i + 1;
                r = n - 1;
                while (l < r) {
                    if (nums[i] + nums[l] + nums[r] == 0) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        temp.clear();
                        l++;
                        while (nums[l] == nums[l - 1])
                            l++;
                        r--;
                        while (nums[r] == nums[r + 1])
                            r--;
                    }
                    else if (nums[i] + nums[l] + nums[r] < 0) {
                        l++;
                    }
                    else if (nums[i] + nums[l] + nums[r] > 0) {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
