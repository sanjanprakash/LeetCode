class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor = 0;
        int isolated_set_bit;
        vector<int>ans(2,0);
        for (auto &x : nums)
            all_xor ^= x;
        isolated_set_bit = all_xor & ~(all_xor-1);
        for (auto &x : nums) {
            if (x & isolated_set_bit)
                ans[0] ^= x;
            else
                ans[1] ^= x;
        }
        return ans;
    }
};
