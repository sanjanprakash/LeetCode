class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int r, c;
        double surplus;
        double glasses[query_row+2][query_row+2];
        for (r = 0; r <= query_row; r++) {
            for (c = 0; c <= r; c++)
                glasses[r][c] = 0.0;
        }
        glasses[0][0] = (int) poured;
        for (r = 0; r <= query_row; r++) {
            for (c = 0; c <= r; c++) {
                surplus = (glasses[r][c] - 1.0)/2.0;
                if (surplus > 0.0) {
                    glasses[r+1][c] += surplus;
                    glasses[r+1][c+1] += surplus;
                }
            }
        }
        return min(1.0, glasses[query_row][query_glass]);
    }
};
