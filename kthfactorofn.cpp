class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        while (k && i <= n) {
            if (n%i == 0)
                k--;
            i++;
        }
        return k ? -1 : i-1;
    }
};
