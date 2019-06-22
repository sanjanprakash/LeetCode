bool sorter(vector<int> A, vector<int> B) {
    return A[1] < B[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i;
        int last, ans = 0;
        if (intervals.size()) {
            sort(intervals.begin(),intervals.end(),sorter);
            last = intervals[0][1];
            for (i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] < last)
                    ans++;
                else
                    last = intervals[i][1];
            }
        }
        return ans;
    }
};
