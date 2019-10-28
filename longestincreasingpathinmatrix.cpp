class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int i,j;
        int m = matrix.size(),n;
        int ans = 0;
        vector<vector<int> > zeros,temp;
        vector<vector<int> > dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        if (m) {
            n = matrix[0].size();
            vector<vector<int> > ins(m,vector<int>(n,0));
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    for (auto &x : dirs) {
                        if (i+x[0] > -1 && i+x[0] < m && j+x[1] > -1 && j+x[1] < n) {
                            if (matrix[i+x[0]][j+x[1]] < matrix[i][j])
                                ins[i][j]++;
                        }
                    }
                    if (!ins[i][j])
                        zeros.push_back({i,j});
                }
            }
            while (zeros.size()) {
                temp.clear();
                ans++;
                for (auto &pt : zeros) {
                    for (auto &x : dirs) {
                        if (pt[0]+x[0] > -1 && pt[0]+x[0] < m && pt[1]+x[1] > -1 && pt[1]+x[1] < n) {
                            if (matrix[pt[0]+x[0]][pt[1]+x[1]] > matrix[pt[0]][pt[1]]) {
                                ins[pt[0]+x[0]][pt[1]+x[1]]--;
                                if (!ins[pt[0]+x[0]][pt[1]+x[1]])
                                    temp.push_back({pt[0]+x[0],pt[1]+x[1]});
                            }
                        }
                    }
                }
                zeros = temp;
            }
        }
        return ans;
    }
};
