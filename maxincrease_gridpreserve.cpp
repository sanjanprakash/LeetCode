class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int i,j;
        int max, ans = 0;
        vector<int>row,col;
        for (i = 0; i < m; i++) {
            max = INT_MIN;
            for (j = 0; j < n; j++) {
                if (grid[i][j] > max)
                    max = grid[i][j];
            }
            row.push_back(max);
        }
        for (i = 0; i < n; i++) {
            max = INT_MIN;
            for (j = 0; j < m; j++) {
                if (grid[j][i] > max)
                    max = grid[j][i];
            }
            col.push_back(max);
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (row[i] < col[j]) {
                    ans += row[i] - grid[i][j];
                }
                else
                    ans += col[j] - grid[i][j];
            }
        }
        return ans;
    }
};
