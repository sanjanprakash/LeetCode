class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num > 1) {
            if (num%4)
                break;
            num /= 4;
        }
        return num == 1;
    }
};
