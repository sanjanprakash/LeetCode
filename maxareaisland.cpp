class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int seen) {
        int r = grid.size(), c = grid[0].size();
        if (x < 0 || x >= r || y < 0 || y >= c || !grid[x][y] || visited[x][y]) {
            return 0;
        }
        visited[x][y] = true;
        return 1 + dfs(grid, visited, x+1, y, seen) + dfs(grid, visited, x, y+1, seen) +
            dfs(grid, visited, x, y-1, seen) + dfs(grid, visited, x-1, y, seen);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = INT_MIN;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans = max(ans, dfs(grid, visited, i, j, 1));
            }
        }
        return ans;
    }
};
