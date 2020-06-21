class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int i, j;
        int r = dungeon.size(), c = dungeon[0].size();
        int best;
        vector<vector<int>> dp (r, vector<int>(c,0));
        dp[r-1][c-1] = dungeon[r-1][c-1] >= 0 ? 1 : -(dungeon[r-1][c-1] - 1);
        
        for (i = c-2; i >= 0; i--)
            dp[r-1][i] = max(1, dp[r-1][i+1]-dungeon[r-1][i]);
        for (i = r-2; i >= 0; i--)
            dp[i][c-1] = max(1, dp[i+1][c-1]-dungeon[i][c-1]);
        
        for (i = r-2; i >= 0; i--) {
            for (j = c-2; j >= 0; j--) {
                best = min(dp[i][j+1], dp[i+1][j]);
                dp[i][j] = max(1, best-dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};
