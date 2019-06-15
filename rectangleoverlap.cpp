class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long int r = min(rec1[2],rec2[2]);
        long long int l = max(rec1[0],rec2[0]);
        long long int u = min(rec1[3],rec2[3]);
        long long int d = max(rec1[1],rec2[1]);
        return r-l > 0 && u-d > 0 && (r-l)*(u-d);
    }
};
