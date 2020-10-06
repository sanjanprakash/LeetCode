class Solution {
public:
    int bitwiseComplement(int N) {
        int k = 1;
        if (!N)
            return 1;
        while (k <= N)
            k *= 2;
        k--;
        return k-N;
    }
};
