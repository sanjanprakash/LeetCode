class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i, j;
        int bit_sum, ans = 0;
        int bit;
        for (i = 0; i < 32; i++) {
            bit_sum = 0;
            bit = 1 << i;
            for (int &x : nums) {
                if (bit & x)
                    bit_sum++;
            }
            if (bit_sum % 3)
                ans |= bit;
        }
        return ans;
    }
};
