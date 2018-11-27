class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>rows,cols;
        int i,j,k;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (k = 0; k < rows.size(); k++) {
            for (i = 0; i < r; i++)
                matrix[i][cols[k]] = 0;
            for (i = 0; i < c; i++)
                matrix[rows[k]][i] = 0;
        }
    }
};
