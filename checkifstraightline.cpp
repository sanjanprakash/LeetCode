class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int i, n = coordinates.size();
        int x_diff = coordinates[0][0]-coordinates[1][0];
        int y_diff = coordinates[0][1]-coordinates[1][1];
        if (n == 2)
            return true;
        for (i = 2; i < n; i++) {
            if (x_diff*(coordinates[2][1]-coordinates[0][1]) != y_diff*(coordinates[2][0]-coordinates[0][0]))
               return false; 
        }
        return true;
    }
};
