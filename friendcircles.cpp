class Solution {
public:
    vector<int> dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& group) {
        int i, n = graph.size();
        visited[curr] = true;
        group.push_back(curr);
        for (i = 0; i < n; i++) {
            if (graph[curr][i] && !visited[i])
                group = dfs(i, graph, visited, group);
        }
        return group;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int i, n = M.size();
        vector<bool> visited(n, false);
        vector<int> group;
        vector<vector<int>> components;
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                group.clear();
                components.push_back(dfs(i, M, visited, group));
            }
        }
        return components.size();
    }
};
