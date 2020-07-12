class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int bits = 0;
        uint32_t ans = 0;
        while (n) {
            ans *= 2;
            ans += n%2;
            n /= 2;
            bits++;
        }
        while (bits < 32) {
            ans *= 2;
            bits++;
        }
        return ans;
    }
};
