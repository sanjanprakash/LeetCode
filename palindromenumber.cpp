class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int rev = 0,x_copy = x;
        while (x > 0) {
            rev *= 10;
            rev += x % 10;
            x /= 10;
        }
        if (rev == x_copy)
            return true;
        return false;
    }
};
