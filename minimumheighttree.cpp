class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        int i,s;
        vector<int> ans;
        int curr;
        queue<int> Q;
        int *n_count = new int[n];
        vector<vector<int> > edge_map;
        for (i = 0; i < n; i++) {
            n_count[i] = 0;      
            edge_map.push_back(ans);
        }
        for (i = 0; i < edges.size(); i++) {
            edge_map[edges[i].first].push_back(edges[i].second);
            edge_map[edges[i].second].push_back(edges[i].first);
            n_count[edges[i].first]++;
            n_count[edges[i].second]++;
        }
        for (i = 0; i < n; i++) {
             if (n_count[i] == 0 || n_count[i] == 1)
                 Q.push(i);
        }
        while (!Q.empty()) {
            s = Q.size();
            ans.clear();
            while (s > 0) {
                curr = Q.front();
                Q.pop();
                s--;
                ans.push_back(curr);
                for (i = 0; i < edge_map[curr].size(); i++) {
                    n_count[edge_map[curr][i]]--;
                    if (n_count[edge_map[curr][i]] == 1) 
                        Q.push(edge_map[curr][i]);  
                }
            }
        }
        return ans;
    }
};
