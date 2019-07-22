class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int i, n = grid.size();
        int top = 0, side = 0, front = 0;
        int biggest;
        for (auto &x : grid) {
            for (auto &y : x) {
                if (y)
                    top++;
            }
        }
        for (auto &x : grid) {
            biggest = INT_MIN;
            for (auto &y : x)
                biggest = max(biggest,y);
            side += biggest;
        }
        for (i = 0; i < n; i++) {
            biggest = INT_MIN;
            for (auto &x : grid)
                biggest = max(biggest,x[i]);
            front += biggest;
        }
        return top+side+front;
    }
};
