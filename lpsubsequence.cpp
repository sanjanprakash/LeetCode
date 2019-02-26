class Solution {
public:    
    int longestPalindromeSubseq(string s) {
        int i,j;
        int n = s.length();
        vector<vector<int> > check(n+1,vector<int> (n+1,0));
        for (i = 1; i <= n; i++)
            check[i][i] = 1;
        for (i = n; i > 0; i--) {
            for (j = i+1; j <= n; j++) {
                if (s[i-1] != s[j-1]) 
                    check[i][j] = max(check[i][j-1],check[i+1][j]);
                else {
                    if (j == i+1)
                        check[i][j] = 2;
                    else
                        check[i][j] = 2 + check[i+1][j-1];
                }
            }
        }
        return check[1][n];
    }
};
