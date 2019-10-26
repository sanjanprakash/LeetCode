class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), ans = 0;
        vector<int> freqs(2,0);
        while (r < n) {
            freqs[nums[r++]]++;
            while (l < r && freqs[0] > 1) 
                freqs[nums[l++]]--;
            ans = max(ans,r-l);
        }
        return ans;
    }
};
