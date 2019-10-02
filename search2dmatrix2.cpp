class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c;
        int i = r-1, j = 0;
        if (r) {
            c = matrix[0].size();
            while (i > -1 && j < c) {
                if (matrix[i][j] == target)
                    return true;
                if (matrix[i][j] > target)
                    i--;
                else
                    j++;
            }
        }
        return false;
    }
};
