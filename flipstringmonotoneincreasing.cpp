class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int i;
        int ones = 0;
        int ans = 0;
        for (auto x : S) {
            if (x == '0') {
                if (ones) {
                    ans++;
                    ones--;
                }
            }
            else
                ones++;
        }
        return ans;
    }
};
