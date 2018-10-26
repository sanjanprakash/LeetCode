class Solution {
public:
    int uniquePaths(int m, int n) {
        int arr[m][n];
        int i,j;
        for (i = 0; i < m; i++)
            arr[i][0] = 1;
        for (i = 0; i < n; i++)
            arr[0][i] = 1;
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }
        return arr[m-1][n-1];
    }
};
