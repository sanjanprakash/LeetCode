class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int i;
        vector<vector<int> > ans;
        multimap<int,int> m;
        for (i = 0; i < points.size(); i++)
            m.insert({(points[i][0] * points[i][0]) + (points[i][1] * points[i][1]),i});
        for (auto it = m.begin(); K > 0; K--, it++)
            ans.push_back(points[it->second]);
        return ans;
    }
};
