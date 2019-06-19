class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        double s1,s2,s3;
        if (points[0][0] == points[1][0] && points[1][0] == points[2][0])
            return false;
        if (points[0][1] == points[1][1] && points[1][1] == points[2][1])
            return false;
        if (points[0] == points[1] || points[1] == points[2] || points[0] == points[2])
            return false;
        s1 = double(points[0][1]-points[1][1])/double(points[0][0]-points[1][0]);
        s2 = double(points[1][1]-points[2][1])/double(points[1][0]-points[2][0]);
        s3 = double(points[0][1]-points[2][1])/double(points[0][0]-points[2][0]);
        return !(s1 == s2 && s2 == s3);
    }
};
