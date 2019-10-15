class Solution {
public:
    int jump(vector<int>& nums) {
        int i, n = nums.size();
        int best = INT_MIN, ans = 0, end = 0;
        if (n > 1) {
            for (i = 0; i < n; i++) {
                best = max(best,i+nums[i]);
                if (i == end) {
                    ans++;
                    end = best;
                }
                if (end == n-1)
                    break;
            }
        }
        return ans;
    }
};
