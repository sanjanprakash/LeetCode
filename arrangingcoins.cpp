class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0, sum = 0;
        while (sum < n-i) {
            i++;
            sum += i;
        }
        return i;
    }
};
