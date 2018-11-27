class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX;
        int start = 0, end = 0, n = nums.size();
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            end++;
            while (sum >= s) {
                ans = min(ans,end-start);
                sum -= nums[start];
                start++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
