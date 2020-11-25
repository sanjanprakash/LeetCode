class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int i, mod = 0;
        for (i = 1; i <= K; i++) {
            mod = ((mod*10) + 1) % K;
            if (!mod)
                return i;
        }
        return -1;
    }
};
