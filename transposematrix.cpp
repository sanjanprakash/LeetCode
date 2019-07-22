class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int i,j;
        int r = A.size(), c = A[0].size();
        vector<vector<int> > ans(c,vector<int>(r));
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++)
                ans[j][i] = A[i][j];
        }
        return ans;
    }
};
