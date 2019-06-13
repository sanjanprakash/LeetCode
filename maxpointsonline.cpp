class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int i,j;
        int ans, max = -1, dups;
        double slope;
        map<double,int> freqs;
        map<double,int>::iterator it;
        if (points.size() < 2)
            return points.size();
        for (i = 0; i < points.size()-1; i++) {
            dups = 1;
            for (j = i+1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    dups++;
                    continue;
                }
                if (points[i][0] == points[j][0]) {
                    freqs[DBL_MAX]++;
                    continue;
                }
                slope = (10000000000.0*double(points[i][1]-points[j][1]))/(double(points[i][0]-points[j][0]));
                freqs[slope]++;
            }
            if (!freqs.empty()) {
                for (it = freqs.begin(); it != freqs.end(); it++) {
                    if (it->second+dups > max)
                        max = it->second + dups;
                }
                freqs.clear();
            }
            else
                max = dups > max ? dups : max;            
        }
        return max;
    }
};
