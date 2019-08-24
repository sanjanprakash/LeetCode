class Solution {
public:
    pair<int,int> counter(string &str) {
        int zeros = 0, ones = 0;
        for (auto &x : str) {
            if (x == '0')
                zeros++;
            else
                ones++;
        }
        return {zeros,ones};
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i,j;
        pair<int,int> weights;
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for (auto &x : strs) {
            weights = counter(x);
            for (i = m; i >= weights.first; i--) {
                for (j = n; j >= weights.second; j--)
                    dp[i][j] = max(dp[i][j],dp[i-weights.first][j-weights.second]+1);
            }
        }
        return dp[m][n];
    }
};
