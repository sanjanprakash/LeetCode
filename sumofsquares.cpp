class Solution {
public:
    bool judgeSquareSum(int c) {
        int a, b, rem;
        for (b = int(sqrt(c)); b >= 0; b--) {
            rem = c - b*b;
            a = int(sqrt(rem));
            if (a*a == rem)
                return true;
        }
        return false;
    }
};
