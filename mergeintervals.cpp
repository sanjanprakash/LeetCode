/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator < (Interval &A, Interval &B) {
        return A.start < B.start;
    }

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() > 0) {
            sort(intervals.begin(),intervals.end());
            int i, start = intervals[0].start, end = intervals[0].end;
            for (i = 0; i < intervals.size(); i++) {            
                if (intervals[i].start >= start && intervals[i].start <= end && intervals[i].end > end)
                    end = intervals[i].end;
                else if (intervals[i].start > end) {
                    Interval temp(start,end);
                    ans.push_back(temp);
                    start = intervals[i].start;
                    end = intervals[i].end;
                }
            }
            Interval temp(start,end);
            ans.push_back(temp);
        }
        return ans;
    }
};
