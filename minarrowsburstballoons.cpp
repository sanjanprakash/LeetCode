class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int i;
        int end, ans = 0;
        if (points.size()) {
            ans = 1;
            sort(points.begin(),points.end());
            end = points[0][1];
            for (i = 1; i < points.size(); i++) {
                if (end > points[i][1])
                    end = points[i][1];
                else if (end < points[i][0]) {
                    ans++;
                    end = points[i][1];
                }
            }
        }
        return ans;
    }
};
