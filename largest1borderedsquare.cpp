class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int i,j;
        int r = grid.size(), c = grid[0].size(), x = 0;
        int lastRow, lastCol;
        int limit = min(r,c);
        int ans = 0;
        bool oneBorder;
        if (r == 1 && c == 1)
            return grid[0][0];
        while (x < limit) {
            x++;
            oneBorder = false;
            lastRow = x-2;
            while (lastRow < r-1) {
                lastRow++;
                lastCol = x-2;
                while (lastCol < c-1) {
                    lastCol++;
                    i = lastCol;
                    while (i > lastCol-x && grid[lastRow-x+1][i]) 
                        i--;
                    if (i != lastCol-x)
                        continue;
                    i = lastCol;
                    while (i > lastCol-x && grid[lastRow][i])
                        i--;
                    if (i != lastCol-x)
                        continue;
                    i = lastRow;
                    while (i > lastRow-x && grid[i][lastCol-x+1])
                        i--;
                    if (i != lastRow-x)
                        continue;
                    i = lastRow;
                    while (i > lastRow-x && grid[i][lastCol])
                        i--;
                    if (i != lastRow-x)
                        continue;
                    ans = max(x*x,ans);
                    oneBorder = true;
                    if (oneBorder)
                        break;
                    }
                if (oneBorder)
                    break;
            }
        }
        return ans;
    }
};
