class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int i,j,n = grid.size();
        int prev;
        int top = 0, bottom, left = 0, right = 0, front = 0, back = 0;
        for (auto &x : grid) {
            for (auto &y : x) {
                if (y)
                    top++;
            }
        }
        bottom = top;
        for (i = 0; i < n; i++) {
            prev = grid[i][0];
            left += prev;
            for (j = 1; j < n; j++) {
                left += max(0,grid[i][j]-prev);
                prev = grid[i][j];
            }
        }
        for (i = 0; i < n; i++) {
            prev = grid[i][n-1];
            right += prev;
            for (j = n-1; j > -1; j--) {
                right += max(0,grid[i][j]-prev);
                prev = grid[i][j];
            }
        }
        for (i = 0; i < n; i++) {
            prev = grid[0][i];
            back += prev;
            for (j = 1; j < n; j++) {
                left += max(0,grid[j][i]-prev);
                prev = grid[j][i];
            }
        }
        for (i = 0; i < n; i++) {
            prev = grid[n-1][i];
            front += prev;
            for (j = n-1; j > -1; j--) {
                front += max(0,grid[j][i]-prev);
                prev = grid[j][i];
            }
        }
        return top+bottom+left+right+front+back;
    }
};
