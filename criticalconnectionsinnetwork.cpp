class Solution {
private:
    int time;
    vector<vector<int> > bridges;
public:
    Solution() {
        time = 0;
    }
    
    void DFS(vector<vector<int> >& graph, int curr, vector<int>& parents, vector<int>& discovery, vector<int>& oldest, vector<bool>& visited) {
        visited[curr] = true;
        oldest[curr] = time;
        discovery[curr] = time;
        time++;
        
        for (int &nbr : graph[curr]) {
            if (!visited[nbr]) {
                parents[nbr] = curr;
                DFS(graph, nbr, parents, discovery, oldest, visited);
                oldest[curr] = min(oldest[curr], oldest[nbr]);
                
                if (oldest[nbr] > discovery[curr])
                    bridges.push_back({curr, nbr});
            }
            else if (nbr != parents[curr])
                oldest[curr] = min(oldest[curr], discovery[nbr]);                
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int i;
        vector<int> parents(n, -1);
        vector<int> discovery(n, INT_MAX);
        vector<int> oldest(n, INT_MAX);
        vector<bool> visited(n, false);
        vector<vector<int> > graph(n, vector<int>());
        
        for (auto &x : connections) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        for (i = 0; i < n; i++) {
            if (!visited[i])
                DFS(graph, i, parents, discovery, oldest, visited);
        }
        
        return bridges;
    }
};
