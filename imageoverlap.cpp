class Solution {
public:
    int overlap(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y) {
        int i, j;
        int r = A.size(), c = A[0].size();
        int ans = 0;
        for (i = x; i < r; i++) {
            for (j = y; j < c; j++) {
                if (A[i][j] & B[i-x][j-y])
                    ans++;
            }
        }
        return ans;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i, j;
        int r = A.size(), c = A[0].size();
        int ans = INT_MIN;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                ans = max(ans, overlap(A, B, i, j));
                ans = max(ans, overlap(B, A, i, j));
            }
        }
        return ans;
    }
};
