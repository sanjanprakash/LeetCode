class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int i, j;
        int r = matrix.size(), c = matrix[0].size();
        int ans = 0;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (!i || !j)
                    ans += matrix[i][j];
                else if (matrix[i][j]) {
                    matrix[i][j] = min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};
