class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0)
            return 1.0;
        if (x == -1.0) {
            if (n % 2 == 1)
                return x;
            else
                return -x;
        }
        if (n == INT_MIN)
            return 0.0;
        if (n < 0) {
            x = 1/x;
            n *= -1;
        }
        int i;
        double ans = 1;
        for (i = 0; i < n; i++)
            ans *= x;
        return ans;
    }
};
