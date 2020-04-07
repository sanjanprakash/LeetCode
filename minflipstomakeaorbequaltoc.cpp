class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a || b || c) {
            if (!(a%2) && !(b%2)) 
                ans += (c%2);
            else if (!(c%2))
                ans += (a%2) + (b%2);
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return ans;
    }
};
