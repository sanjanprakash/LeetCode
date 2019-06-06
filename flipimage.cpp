class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int i,j;
        int r = A.size(), c = A[0].size();
        int temp;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c/2; j++) {
                temp = A[i][j];
                A[i][j] = A[i][c-j-1] == 1 ? 0 : 1;
                A[i][c-j-1] = temp == 1 ? 0 : 1;
            }
            if (c % 2 == 1)
                A[i][c/2] = A[i][c/2] == 1 ? 0 : 1;
        }
        return A;
    }
};
