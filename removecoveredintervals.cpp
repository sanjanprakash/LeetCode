class Solution {
public:
    static bool compare(vector<int>& A, vector<int>& B) {
        if (A[0] == B[0])
            return A[1] >= B[1];
        return A[0] < B[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int i, n = intervals.size();
        int max_end = INT_MIN;
        int ans = n;
        sort(intervals.begin(), intervals.end(), compare);
        for (i = 0; i < n; i++) {
            if (intervals[i][1] <= max_end)
                ans--;
            max_end = max(intervals[i][1], max_end);
        }
        return ans;
    }
};
