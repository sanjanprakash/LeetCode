class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& grey, int curr) {
        int nodes = 1;
        visited[curr] = true;
        grey[curr] = true;
        for (int x : graph[curr]) {
            if (!visited[x])
                nodes += dfs(graph, visited, grey, x);
        }
        grey[curr] = false;
        return nodes;
    }
    
    int minSwapsCouples(vector<int>& row) {
        int i, n = row.size();
        int swaps = 0;
        vector<int> couches(n, 0);
        vector<vector<int>> couch_graph(n/2, vector<int>());
        vector<bool> visited(n/2, false), grey(n/2, false);
        
        for (i = 0; i < n; i++)
            couches[row[i]] = i/2;
        for (i = 0; i < n; i += 2) {
            if (couches[i] != couches[i+1]) {
                couch_graph[couches[i]].push_back(couches[i+1]);
                couch_graph[couches[i+1]].push_back(couches[i]);
            }   
        }
        
        for (i = 0; i < n/2; i++) {
            if (!visited[i]) 
                swaps += dfs(couch_graph, visited, grey, i) - 1;
        }
        
        return swaps;
    }
};
