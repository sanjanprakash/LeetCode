class Solution {
public:
    int bitwiseComplement(int N) {
        int mult = 1, ans = 0;
        vector<int> bits;
        if (!N)
            return 1;
        while (N) {
            bits.push_back(N%2);
            N /= 2;
        }
        for (auto &x : bits) {
            if (!x)
                ans += mult;
            mult *= 2;
        }
        return ans;
    }
};
