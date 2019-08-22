class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int i, j, n = grid.size();
        int x, y;
        int ans = -1;
        pair<int,pair<int,int> > pred;
        queue<pair<int,pair<int,int> > > Q;
        if (n > 1) {
            queue<pair<int,pair<int,int> > > Q;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 2;
                        Q.push({0,{i,j}});
                    }
                }
            }
            while (!Q.empty()) {
                pred = Q.front();
                Q.pop();
                x = pred.second.first;
                y = pred.second.second;
                if (x+1 < n && !grid[x+1][y]) {
                    Q.push({pred.first+1,{x+1,y}});
                    grid[x+1][y] = 2;
                    ans = max(ans,pred.first+1);
                }
                if (x-1 > -1 && !grid[x-1][y]) {
                    Q.push({pred.first+1,{x-1,y}});
                    grid[x-1][y] = 2;
                    ans = max(ans,pred.first+1);
                }
                if (y+1 < n && !grid[x][y+1]) {
                    Q.push({pred.first+1,{x,y+1}});
                    grid[x][y+1] = 2;
                    ans = max(ans,pred.first+1);
                }
                if (y-1 > -1 && !grid[x][y-1]) {
                    Q.push({pred.first+1,{x,y-1}});
                    grid[x][y-1] = 2;
                    ans = max(ans,pred.first+1);
                }
            }
        }
        return ans;
    }
};
