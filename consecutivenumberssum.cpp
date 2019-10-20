class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int k, ans = 0;
        k = 2;
        while (2*N-k*(k+1) >= 0) {
            if ((N-(k/2))%k == 0)
                ans++;
            k += 2;
        }
        k = 1;
        while (2*N-k*(k+1) >= 0) {
            if (N%k == 0)
                ans++;
            k += 2;
        }
        return ans;
    }
};
