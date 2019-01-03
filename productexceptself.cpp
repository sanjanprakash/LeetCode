class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int i, n = nums.size();
        int start = 1, end = 1;
        for (i = 0; i < n; i++)
            ans.push_back(1);
        for (i = 0; i < n; i++) {
            ans[i] *= start;
            start *= nums[i];
            ans[n-i-1] *= end;
            end *= nums[n-i-1];
        }
        return ans;
    }
};
