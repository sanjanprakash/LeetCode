class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int i, ans = 0;
        sort(nums.begin(),nums.end());
        for (i = 0; i < nums.size(); i += 2)
            ans += nums[i];
        return ans;
    }
};
