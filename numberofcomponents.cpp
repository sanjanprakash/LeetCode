class Solution {
public:
    void islandMark(vector<vector<char>>& grid, int i, int j) {
        int r = grid.size();
        int c = grid[0].size();
        if (i >= 0 && j >= 0 && i < r && j < c) {
            if (grid[i][j] == '1') {
                grid[i][j] = 'x';
                islandMark(grid,i-1,j);
                islandMark(grid,i+1,j);
                islandMark(grid,i,j-1);
                islandMark(grid,i,j+1);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if (r == 0)
            return 0;
        int c = grid[0].size();
        if (c == 0)
            return 0;
        int i,j;
        int count = 0;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    islandMark(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
