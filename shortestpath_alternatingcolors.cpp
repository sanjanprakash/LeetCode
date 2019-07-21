class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> distEndBlue(n,INT_MAX-1), distEndRed(n,INT_MAX-1), ans(n,0);    
        unordered_map<int,vector<pair<int,char> > > G;
        for (auto &x : red_edges) 
            G[x[0]].push_back({x[1],'r'});
        for (auto &x : blue_edges) 
            G[x[0]].push_back({x[1],'b'});
        queue<int> Q;
        Q.push(0);
        distEndBlue[0] = 0;
        distEndRed[0] = 0;
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (auto x : G[v]) {
                if (x.second == 'b' && distEndRed[v] + 1 < distEndBlue[x.first]) {
                   distEndBlue[x.first] = distEndRed[v] + 1;
                   Q.push(x.first);
                }
                if (x.second == 'r' && distEndBlue[v] + 1 < distEndRed[x.first]) {
                   distEndRed[x.first] = distEndBlue[v] + 1;
                   Q.push(x.first);            
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] = min(distEndBlue[i],distEndRed[i]);
            if (ans[i] == INT_MAX-1)
                ans[i] = -1;
        }
        return ans;
    }
};
