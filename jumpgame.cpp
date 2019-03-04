class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, i = 0;
        if (n < 2)
            return true;
        while (i <= curr && i < n) {
            if (i + nums[i] > curr)
                curr = i + nums[i];
            i++;
        }
        return i == n;    
    }
};
