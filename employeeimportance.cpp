/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    void dfs(int curr_id, unordered_map<int,vector<int> >& subs, unordered_map<int,int>& importance, unordered_map<int,bool>& visited, int& ans) {
        if (!visited[curr_id]) {
            ans += importance[curr_id];
            visited[curr_id] = true;
            for (auto x : subs[curr_id]) {
                if (!visited[x])
                    dfs(x,subs,importance,visited,ans);
            }
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        unordered_map<int,vector<int> > subs;
        unordered_map<int,int> importance;
        unordered_map<int,bool> visited;
        for (auto &x : employees) {
            subs[x->id] = x->subordinates;
            importance[x->id] = x->importance;
            visited[x->id] = false;
        }
        dfs(id,subs,importance,visited,ans);
        return ans;
    }
};
