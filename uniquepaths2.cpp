class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int arr[m][n],i,j;
        for (i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                arr[i][0] = 0;
            else {
                if (i == 0)
                    arr[i][0] = 1;
                else
                    arr[i][0] = arr[i-1][0];
            }
        }
        for (i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1)
                arr[0][i] = 0;
            else {
                if (i == 0)
                    arr[0][i] = 1;
                else
                    arr[0][i] = arr[0][i-1];
            }
        }
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    arr[i][j] = 0;
                else 
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }
        return arr[m-1][n-1];
    }
};
