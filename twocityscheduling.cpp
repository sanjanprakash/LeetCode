class Solution {
private:
    static bool sorter(const pair<int,int> A, const pair<int,int> B) {
        return A.first > B.first;
    }
public:    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int i, n = costs.size();
        int ans = 0;
        vector<pair<int,int> > diffs;
        for (i = 0; i < n; i++)
            diffs.push_back(make_pair(costs[i][0]-costs[i][1],i));
        sort(diffs.begin(),diffs.end(),sorter);
        for (i = 0; i < n; i++) 
            ans += (i < n/2) ? costs[diffs[i].second][1] : costs[diffs[i].second][0];
        return ans;
    }
};
