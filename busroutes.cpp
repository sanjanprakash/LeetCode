class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int i,j;
        pair<int,int> pred;
        queue<pair<int,int> > Q;
        unordered_map<int,bool> visited;
        unordered_map<int,unordered_map<int,int> > bus2stop, stop2bus;
        if (S == T)
            return 0;
        for (i = 0; i < routes.size(); i++) {
            for (j = 0; j < routes[i].size(); j++) {
                bus2stop[i][routes[i][j]]++;
                stop2bus[routes[i][j]][i]++;
            }
        }
        for (auto &x : stop2bus[S]) {
            Q.push({x.first,1});
            visited[x.first] = true;
        }
        while (!Q.empty()) {
            pred = Q.front();
            Q.pop();
            if (bus2stop[pred.first].find(T) != bus2stop[pred.first].end())
                return pred.second;
            for (auto &stop : bus2stop[pred.first]) {
                for (auto &bus : stop2bus[stop.first]) {
                    if (!visited[bus.first]) {
                        
                        Q.push({bus.first,pred.second+1});
                        visited[bus.first] = true;
                    }
                }
            }
        }
        return -1;
    }
};
