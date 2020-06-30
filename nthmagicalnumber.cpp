class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long long int lcm = A/gcd(A, B)*B;
        long long int l = 0, h = N * (long)min(A, B), m;
        while (l < h) {
            m = l + (h-l)/2;
            if (m/A + m/B - m/lcm < N)
                l = m+1;
            else
                h = m;
        }
        return l%1000000007;
    }
};
