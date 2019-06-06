class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int xo = x^y;
        while (xo > 0) {
            if (xo % 2 == 1)
                ans++;
            xo = xo >> 1;
        }
        return ans;
    }
};
