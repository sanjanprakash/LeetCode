class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i, n = bits.size();
        vector<bool> dp(n,true);
        for (i = 0; i < n; i++) {
            if (bits[i] == 1) {
                dp[i] = false;
                dp[i+1] = false;
                i++;
            }
        }
        return dp[n-1];
    }
};
