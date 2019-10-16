class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i, j, n = intervals.size();
        int neo_s, neo_e;
        vector<vector<int> > ans;
        for (i = 0; i < n; i++) {
            if (intervals[i][1] >= newInterval[0])
                break;
            ans.push_back(intervals[i]);
        }
        if (i == n) {
            intervals.push_back(newInterval);
            return intervals;
        }
        else {
            j = i;
            while (j < n && intervals[j][0] <= newInterval[1])
                j++;
            neo_s = min(intervals[i][0],newInterval[0]);
            neo_e = j ? max(newInterval[1],intervals[j-1][1]) : newInterval[1];
            ans.push_back({neo_s,neo_e});
            while (j < n) {
                ans.push_back(intervals[j]);
                j++;
            }
            return ans;
        }
    }
};
