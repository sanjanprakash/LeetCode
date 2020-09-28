class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>& graph, unordered_map<string, bool>& visited, string curr, string dest, double curr_prod, double& ans) {
        if (visited[curr])
            return;
        if (curr == dest) {
            ans = curr_prod;
            return;
        }
        visited[curr] = true;
        for (auto &x : graph[curr])
            dfs(graph, visited, x.first, dest, curr_prod*x.second, ans);
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int i, n = equations.size();
        double res;
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for (i = 0; i < n; i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        for (auto &x : queries) {
            unordered_map<string, bool> visited;
            if (graph.find(x[0]) == graph.end() || graph.find(x[1]) == graph.end()) 
                ans.push_back(-1.0);
            else {
                res = -1.0;
                dfs(graph, visited, x[0], x[1], 1.0, res);
                ans.push_back(res);
            }
        }
        return ans;
    }
};
