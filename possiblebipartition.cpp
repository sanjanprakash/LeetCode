class Solution {
public:
    bool dfs(vector<vector<int> >& graph, vector<int> &colors, int start) {
        int nbr = colors[start] == 1 ? 2 : 1;
        bool ans;
        for (int &x : graph[start]) {
            if (!colors[x]) {
                colors[x] = nbr;
                ans = dfs(graph, colors, x);
                if (!ans)
                    return false;
            }
            else if (colors[start] == colors[x])
                return false;
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int i;
        bool ans;
        vector<vector<int> > graph(N+1, vector<int>());
        vector<int> colors(N+1, 0);
        for (auto &x : dislikes) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for (i = 1; i <= N; i++) {
            if (!colors[i]) {
                colors[i] = 1;
                ans = dfs(graph, colors, i);
                if (!ans)
                    return false;
            }
        }
        return true;
    }
};
