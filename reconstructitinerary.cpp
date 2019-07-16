class Solution {
private:
    unordered_map<string, deque<string> > graph;
    vector<string> ans;
    
public:
    void dfs(string curr) {
        string next;
        if (curr.length()) {
            while (!graph[curr].empty()) {
                    next = graph[curr][0];
                    graph[curr].pop_front();
                    dfs(next);
            }
            ans.push_back(curr);
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int time = 0;
        for (auto &x : tickets) 
            graph[x[0]].push_back(x[1]);
        for (auto &x : graph)
            sort(x.second.begin(),x.second.end());
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
