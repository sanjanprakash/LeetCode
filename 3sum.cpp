class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, n = nums.size();
        int l, r, sum;
        vector<int> temp;
        set<vector<int>> possibilities;
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for (i = 0; i < n-2; i++) {
            l = i+1, r = n-1;
            while (l < r) {
                sum = nums[i]+nums[l]+nums[r];
                if (sum == 0) {
                    possibilities.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (sum > 0)
                    r--;
                else
                    l++;
            }
        }
        for (auto &x : possibilities)
            ans.push_back(x);
        
        return ans;
    }
};
