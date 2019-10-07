class NumMatrix {
private:
    int **dp;
    int r,c;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int i, j;
        r = matrix.size();
        if (r) {
            c = matrix[0].size();
            dp = new int*[r];
            for (i = 0; i < r; i++)
                dp[i] = new int[c];
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (i == 0) 
                        dp[i][j] = matrix[i][j] + ((j == 0) ? 0 : dp[i][j-1]);
                    else 
                        dp[i][j] = dp[i-1][j] + matrix[i][j] + ((j == 0) ? 0 : dp[i][j-1]-dp[i-1][j-1]);
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return r ? dp[row2][col2] - (row1 == 0 ? 0 : dp[row1-1][col2]) - (col1 == 0 ? 0 : dp[row2][col1-1]) + (col1 == 0 || row1 == 0 ? 0 : dp[row1-1][col1-1]) : 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
