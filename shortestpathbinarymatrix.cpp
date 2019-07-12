class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int i,j;
        int n = grid.size();
        int pred_x, pred_y;
        vector<vector<bool> > visited(n,vector<bool>(n,false));
        pair<pair<int,int>,int> pred;
        queue<pair<pair<int,int>,int> >  Q;
        
        if (n == 1)
            return grid[0][0] == 0 ? 1 : -1;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) 
            return -1;
        
        Q.push(make_pair(make_pair(0,0),1));
        visited[0][0] = true;
        while (!Q.empty()) {
            pred = Q.front();
            pred_x = pred.first.first;
            pred_y = pred.first.second;
            Q.pop();
            for (i = -1; i < 2; i++) {
                for (j = -1; j < 2; j++) {
                    if (i == 0 && j == 0)
                        continue;
                    if (pred_x+i >= 0 && pred_x+i < n && pred_y+j >= 0 && pred_y+j < n && !grid[pred_x+i][pred_y+j] && !visited[pred_x+i][pred_y+j]) {
                        if (pred_x+i == n-1 && pred_y+j == n-1)
                            return pred.second+1;
                        visited[pred_x+i][pred_y+j] = true;
                        Q.push(make_pair(make_pair(pred_x+i,pred_y+j),pred.second+1));
                    }
                }
            }
        }
        return -1;
    }
};
