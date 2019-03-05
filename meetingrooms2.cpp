/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int i;
        int ans = 0;
        int sum = 0;
        pair<int,int> p;
        vector<pair<int,int> > x;
        for (i = 0; i < intervals.size(); i++) {
            p = make_pair(intervals[i].start,1);
            x.push_back(p);
            p = make_pair(intervals[i].end,-1);
            x.push_back(p);
        }
        sort(x.begin(),x.end());
        for (i = 0 ; i < x.size(); i++) {
            sum += x[i].second;
            ans = max(ans,sum);
        }
        return ans;
    }
};
