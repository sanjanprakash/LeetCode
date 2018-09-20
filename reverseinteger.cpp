class Solution {
public:
    int reverse(int x) {
        int ans = 0,prev = 0;
        bool negative = false;
        if (x < 0) {
            x *= -1;
            negative = true;
        }
        while (x != 0) {
            ans *= 10;
            ans += x % 10;
            if ((ans - (x % 10))/10 != prev)
                return 0;
            x /= 10;
            prev = ans;
        }
        if (negative == true)
            ans *= -1;
        return ans;
    }
};
