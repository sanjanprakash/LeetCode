class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i, sum = 0;
        int ans = 0;
        unordered_map<int,int> sum_freqs;
        sum_freqs[0] = 1;
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum_freqs[sum-k])
                ans += sum_freqs[sum-k];
            sum_freqs[sum]++;
        }
        return ans;
    }
};
