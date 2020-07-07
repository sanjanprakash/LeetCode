class Solution {
public:
    int numNbrs(vector<vector<int>>& grid, int x, int y) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        if (x > 0 && grid[x-1][y])
            ans++;
        if (x < r-1 && grid[x+1][y])
            ans++;
        if (y > 0 && grid[x][y-1])
            ans++;
        if (y < c-1 && grid[x][y+1])
            ans++;
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j;
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (grid[i][j])
                    ans += 4-numNbrs(grid, i, j);
            }
        }
        return ans;
    }
};
