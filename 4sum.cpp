class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
            int n = nums.size();
            if (n == 0)
                return ans;
            vector<int> temp;
            sort(nums.begin(),nums.end());
            int i, j, l, r;
            for (i = 0; i < n - 3; i++) {
                if ((i > 0 && nums[i] != nums[i - 1]) || i == 0) {
                    //j = i + 1;
                    for (j = i + 1; j < n - 2; j++) {
                        if ((nums[j] != nums[j - 1] && j > i) || j == i + 1) {
                            l = j + 1;
                            r = n - 1;
                            while (l < r) {
                                if (nums[i] + nums[j] + nums[l] + nums[r] == target) {
                                    temp.push_back(nums[i]);
                                    temp.push_back(nums[j]);
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
                                else if (nums[i] + nums[j] + nums[l] + nums[r] < target) {
                                    l++;
                                }
                                else if (nums[i] + nums[j] + nums[l] + nums[r] > target) {
                                    r--;
                                }
                            }
                        }
                    }
                }
            }
            return ans;    
    }
};
