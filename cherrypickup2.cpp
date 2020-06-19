class Solution {
public:
    int best(vector<vector<int> > &nextRow, int a, int b) {
        int c = nextRow.size(), ans = INT_MIN;
        int p, q;
        vector<int> candidates, dirs = {-1, 0, 1};
        for (int &a_next : dirs) {
            for (int &b_next : dirs) {
                p = a + a_next;
                q = b + b_next;
                if (p > -1 && p < c && q > -1 && q < c && p != q)
                    candidates.push_back(nextRow[p][q]);
            }
        }
        for (int &x : candidates)
            ans = max(x, ans);
        return ans;
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int i, j, k;
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int> > > dp(2, vector<vector<int> > (c, vector<int>(c, 0)));
        
        for (i = 0; i < c; i++) {
            for (j = 0; j < c; j++) {
                if (i != j)
                    dp[1][i][j] = grid[r-1][i] + grid[r-1][j];
            }
        }
        
        for (i = r-2; i >= 0; i--) {
            for (j = 0; j < c; j++) {
                for (k = 0; k < c; k++) {
                    if (j != k) 
                        dp[0][j][k] = grid[i][j] + grid[i][k] + best(dp[1], j, k);
                }
            }
            dp[1] = dp[0];
        }
        return dp[0][0][c-1];
    }
};
