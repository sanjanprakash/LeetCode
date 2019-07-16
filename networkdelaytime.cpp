class Compare {
public:
    int operator()(pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int i, ans = INT_MIN;
        pair<int,int> curr;
        vector<int> dist(N,INT_MAX);
        unordered_map<int,vector<pair<int,int> > > graph; 
        priority_queue<pair<int,int>, vector<pair<int,int> >,  Compare> pq;
        dist[K-1] = 0;
        for (auto &x : times) 
            graph[x[0]].push_back({x[1],x[2]});        
        for (i = 1; i <= N; i++) 
            pq.push({i,dist[i-1]});
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            for (auto &x : graph[curr.first]) {
                if (dist[curr.first-1] != INT_MAX && dist[x.first-1] > dist[curr.first-1] + x.second) {
                    dist[x.first-1] = dist[curr.first-1] + x.second;
                    pq.push({x.first,dist[x.first-1]});
                }
            }
        }
        for (auto &x : dist) 
            ans = max(ans,x);
        return ans == INT_MAX ? -1 : ans;
    }
};
