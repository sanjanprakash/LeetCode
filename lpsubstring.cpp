class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0,end = 0;
        int max_length = INT_MIN;
        int i,j;
        string ans = "";
        vector<vector<bool>> dp = vector(n,vector<bool>(n,false));
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++)
                dp[i][j] = true;            
        }
        
        for (i = n-1; i >= 0; i--) {
            dp[i][i] = true;
            for (j = i+1; j < n; j++) {
                if (s[i] == s[j] && dp[i+1][j-1] == true) {
                    dp[i][j] = true;
                    if (max_length < j-i+1) {
                        max_length = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        for (i = start; i <= end; i++)
            ans += s[i];
        return ans;
    }
};
