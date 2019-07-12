class Solution {
public:
    bool cycleCheck(int curr, unordered_map<int,vector<int> >& graph, vector<bool>& black, vector<bool>& grey) {
        if (!black[curr]) {
            black[curr] = true;
            grey[curr] = true;
            for (auto adj : graph[curr]) {
                if (!black[adj] && cycleCheck(adj,graph,black,grey))
                    return true;
                else if (grey[adj])
                    return true;
            }
        }
        grey[curr] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i;
        unordered_map<int,vector<int> > graph;
        vector<bool> black(numCourses,false), grey(numCourses,false);
        for (auto x : prerequisites) 
            graph[x[1]].push_back(x[0]);
        for (i = 0; i < numCourses; i++) {
            if (!black[i] && cycleCheck(i,graph,black,grey))
                return false;
        }
        return true;
    }
};
