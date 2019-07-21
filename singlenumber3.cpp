class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor = 0;
        int div = 1;
        int isolated_set_bit, set_a = 0 , set_b = 0;
        vector<int>ans(2,0);
        for (auto &x : nums)
            all_xor ^= x;
        isolated_set_bit = all_xor & ~(all_xor-1);
        for (auto &x : nums) {
            if (x & isolated_set_bit)
                set_a ^= x;
            else
                set_b ^= x;
        }
        ans[0] = set_a;
        ans[1] = set_b;
        return ans;
    }
};
