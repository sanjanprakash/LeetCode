class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m,n,i,j,min_cost;
        m = grid.size();
        n = grid[0].size();
        int arr[m][n];
        arr[0][0] = grid[0][0];
        for (i = 1; i < m; i++)
            arr[i][0] = grid[i][0] + arr[i-1][0];
        for (i = 1; i < n; i++)
            arr[0][i] = grid[0][i] + arr[0][i-1];
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                min_cost = arr[i-1][j];
                if (arr[i][j-1] < arr[i-1][j])
                    min_cost = arr[i][j-1];
                arr[i][j] = grid[i][j] + min_cost;
            }
        }
        return arr[m-1][n-1];
    }
};
