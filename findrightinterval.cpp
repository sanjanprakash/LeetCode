class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int i;
        vector<int> ans(intervals.size(),-1);
        map<vector<int>,int> ids;
        map<vector<int>,int>::iterator it;
        for (i = 0; i < intervals.size(); i++) 
            ids[intervals[i]] = i;
        for (i = 0; i < intervals.size(); i++) {
            it = ids.find(intervals[i]);
            it++;
            while (it != ids.end() && it->first[0] < intervals[i][1])
                it++;
            if (it != ids.end())
                ans[i] = it->second;
        }
        return ans;
    }
};
