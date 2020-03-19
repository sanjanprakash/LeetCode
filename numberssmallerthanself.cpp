class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, n = nums.size();
        int same = 0;
        vector<int> ans(n, 0);
        vector<vector<int> > sorted;
        for (i = 0; i < n; i++)
            sorted.push_back({nums[i], i});
        sort(sorted.begin(), sorted.end());
        for (i = 0; i < n; i++) {
            if (i > 0)
                sorted[i-1][0] == sorted[i][0] ? same++ : same = 0;
            ans[sorted[i][1]] = i-same;
        }
        return ans;
    }
};
