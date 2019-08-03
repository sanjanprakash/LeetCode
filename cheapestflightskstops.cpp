class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int stops[n] = {0};
        int costs[n];
        for (auto &x : costs)
            x = INT_MAX;
        vector<vector<pair<int,int> > > graph(n,vector<pair<int,int> >());
        pair<int,int> curr;
        priority_queue<pair<int,int> > PQ;
        for (auto &x : flights) 
            graph[x[0]].push_back({x[1],x[2]});
        PQ.push({0,src});
        costs[src] = 0;
        while (!PQ.empty()) {
            curr = PQ.top();
            PQ.pop();
            for (auto &x : graph[curr.second]) {
                if (costs[x.first] > x.second+curr.first && stops[curr.second] <= K) {
                    PQ.push({x.second+curr.first,x.first});
                    costs[x.first] = x.second+curr.first;
                    stops[x.first] = stops[curr.second]+1;
                }
            }
        }
        return stops[dst] <= K+1 && costs[dst] != INT_MAX ? costs[dst] : -1;
    }
};
