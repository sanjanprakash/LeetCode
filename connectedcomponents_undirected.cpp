class Solution {
public:
    void dfs(int u, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[u] = true;
        for (int v : graph[u]) {
            if (!visited[v])
                dfs(v, graph, visited);
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        int i, ans = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                ans++;
            }
        }        
        
        return ans;
    }
};
