class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i,n = nums.size();
        int sum = 0, real_sum = n*(n+1)/2;
        vector<int> freq(n,0);
        vector<int> ans;
        for (i = 0; i < n; i++) {
            sum += nums[i];
            freq[nums[i]-1]++;
            if (freq[nums[i]-1] == 2)
                ans.push_back(nums[i]);
        }
        ans.push_back(real_sum-sum+ans[0]);
        return ans;
    }
};
