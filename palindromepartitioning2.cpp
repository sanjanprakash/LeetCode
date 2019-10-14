class Solution {
public:
    int minCut(string s) {
        int i,j,k;
        int n = s.length(), best;
        vector<vector<bool> > isPalindrome(n,vector<bool>(n,false));
        vector<int> dp(n,0);
        if (n > 1) {
            for (i = 0; i < n; i++) {
                isPalindrome[i][i] = true;
                if (i < n-1 && s[i] == s[i+1]) 
                    isPalindrome[i][i+1] = true;
            }
            for (k = 3; k <= n; k++) {
                for (i = 0; i < n-k+1; i++) {
                    if (s[i] == s[i+k-1])
                        isPalindrome[i][i+k-1] = isPalindrome[i+1][i+k-2];
                    else
                        isPalindrome[i][i+k-1] = false;
                }
            }
            
            for (i = 1; i < n; i++) {
                best = dp[i-1];
                if (!isPalindrome[0][i]) {
                    for (j = i-1; j > 0; j--) {
                        if (isPalindrome[j][i])
                            best = min(best,dp[j-1]);
                    }
                    dp[i] = best+1;
                }
                else
                    dp[i] = 0;
            }
        }
        return dp[n-1];
    }
};
