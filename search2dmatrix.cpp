class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lr = 0, rr;
        int lc = 0, rc;
        int mr, mc;
        rr = matrix.size()-1;
        if (rr+1) {
            rc = matrix[0].size()-1;
            while (lr < rr) {
                mr = lr+(rr-lr)/2;
                if (matrix[mr][0] > target)
                    rr = mr-1;
                else if (matrix[mr][rc] < target)
                    lr = mr+1;
                else
                    break;
            }
            if (lr <= rr) {
                mr = lr+(rr-lr)/2;
                while (lc <= rc) {
                    mc = lc+(rc-lc)/2;
                    if (matrix[mr][mc] == target)
                        return true;
                    else if (matrix[mr][mc] < target)
                        lc = mc+1;
                    else
                        rc = mc-1;
                }
            }
        }
        return false;
    }
};
