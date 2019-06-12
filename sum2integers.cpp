class Solution {
public:
    int getSum(int a, int b) {
        int ans = a, carry;
        while (b) {
            ans = a^b;
            carry = (a&b&INT_MAX) << 1;
            a = ans;
            b = carry;
        }
        return ans;
    }
};
