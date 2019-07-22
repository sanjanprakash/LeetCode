class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j;
        int m = grid.size(), n = grid[0].size();
        int t;
        pair<int,int> p;
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int > > Q;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    Q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        while (!Q.empty()) {
            p = Q.front().first;
            t = Q.front().second;
            Q.pop();
            if (p.first+1 < m && grid[p.first+1][p.second] == 1 && !visited[p.first+1][p.second]) {
                visited[p.first+1][p.second] = true;
                Q.push({{p.first+1,p.second},t+1});
            }
            if (p.first-1 > -1&& grid[p.first-1][p.second] == 1 && !visited[p.first-1][p.second]) {
                visited[p.first-1][p.second] = true;
                Q.push({{p.first-1,p.second},t+1});
            }
            if (p.second+1 < n && grid[p.first][p.second+1] == 1 && !visited[p.first][p.second+1]) {
                visited[p.first][p.second+1] = true;
                Q.push({{p.first,p.second+1},t+1});
            }
            if (p.second-1 > -1 && grid[p.first][p.second-1] == 1 && !visited[p.first][p.second-1]) {
                visited[p.first][p.second-1] = true;
                Q.push({{p.first,p.second-1},t+1});
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    cout << i << " " << j << endl;
                    return -1;
                }
            }
        }
        return t;
    }
};
