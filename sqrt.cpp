class Solution {
public:
    int mySqrt(long long int x) {
        long long int i = 1;
        while (i*i <= x)
            i++;
        return i-1;
    }
};
