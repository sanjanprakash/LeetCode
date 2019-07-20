class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int i, n = nums.size(), all_xor = nums[0];
        if (n%2 == 0)
            return true;
        for (i = 1; i < n; i++)
            all_xor ^= nums[i];
        if (!all_xor)
            return true;
        return false;
    }
};
