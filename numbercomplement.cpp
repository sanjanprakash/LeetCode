class Solution {
public:
    int findComplement(int num) {
        int mult = 1, ans = 0, sum = 0;
        vector<int> bits;
        if (!num)
            return 1;
        while (num) {
            bits.push_back(num%2);
            num /= 2;
        }
        for (auto &x : bits)
            sum += x;
        if (sum == bits.size())
            return 0;
        for (auto &x : bits) {
            if (!x)
                ans += mult;
            if (mult < INT_MAX/2)
                mult *= 2;
        }
        return ans;
    }
};
