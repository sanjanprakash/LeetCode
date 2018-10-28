class Solution {
public:
    int divide(int dividend, int divisor) {
        bool pos = true;
        int q;
        if (dividend == 0)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend > 0) {
            pos = !pos;
            dividend = -dividend;
        }
        if (divisor > 0) {
            pos = !pos;
            divisor = -divisor;
        }
        q = Div(dividend,divisor);
        if (pos == false)
            return -q;
        return q;
    }
    
    int Div(int dividend, int divisor) {
        int m, count = 1;
        int leftover;
        if (dividend > divisor)
            return 0;
        m = divisor;
        while (2*m > dividend && 2*m < 0) {
            count += count;
            m += m;
        }
        leftover = dividend - m;
        count += Div(leftover,divisor);
        return count;
    }
};
