class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, ans = INT_MIN, i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            }
            else {
                ans = max(ans,count);
                count = 0;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};
