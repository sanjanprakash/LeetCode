class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy)
            return false;
        if (sy == ty)
            return (tx-sx)%ty == 0;
        return reachingPoints(sy,sx,ty,tx%ty);
    }
};
