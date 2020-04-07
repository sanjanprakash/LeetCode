class Solution {
public:
    int numDecodings(string s) {
        int i, n = s.length();
        int single;
        long long int mod = 1000000007;
        vector<long long int> dp(n, 0);
        for (i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == '0')
                    return 0;
                else if (s[i] == '*')
                    dp[i] = 9;
                else
                    dp[i] = 1;
            }
            else {
                if (s[i] == '*') {
                    dp[i] = 9*dp[i-1];
                    if (s[i-1] == '1') {
                        if (i > 1)
                            dp[i] = (dp[i] + (dp[i-2]*9)%mod)%mod;
                        else
                            dp[i] = (dp[i] + 9)%mod;
                    }
                    else if (s[i-1] == '2') {
                        if (i > 1)
                            dp[i] = (dp[i] + (dp[i-2]*6)%mod)%mod;
                        else
                            dp[i] = (dp[i] + 6)%mod;
                    }
                    else if (s[i-1] == '*') {
                        if (i > 1)
                            dp[i] = (dp[i] + (dp[i-2]*15)%mod)%mod;
                        else
                            dp[i] = (dp[i] + 15)%mod;
                    }
                }
                else {
                    single = s[i]-'0';
                    if (single)
                        dp[i] = dp[i-1];
                    if (s[i-1] == '*') {
                        if (i > 1)
                            dp[i] = (dp[i] + (dp[i-2]*(2 - single/7))%mod)%mod;
                        else
                            dp[i] = (dp[i] + (2 - single/7))%mod;
                    }
                    single += (s[i-1]-'0')*10;
                    if (single >= 10 && single <= 26) {
                        if (i > 1)
                            dp[i] = (dp[i] + dp[i-2]) % mod;
                        else
                            dp[i] = (dp[i] + 1) % mod;
                    }
                }
            }
        }        
        return dp[n-1];
    }
};
