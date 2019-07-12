class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int i;
        int curr;
        vector<int> indegree(numCourses,0), ans, blank;
        unordered_map<int,vector<int> > graph;
        queue<int> Q;
        for (auto x : prerequisites) {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        for (i = 0; i < numCourses; i++) {
            if (!indegree[i])
                Q.push(i);
        }
        while (!Q.empty()) {
            curr = Q.front();
            Q.pop();
            for (auto adj : graph[curr]) {
                indegree[adj]--;
                if (!indegree[adj])
                    Q.push(adj);
            }
            numCourses--;
            ans.push_back(curr);
        }
        return numCourses ? blank : ans;
    }
};
