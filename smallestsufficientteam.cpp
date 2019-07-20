class Solution {
private:
    unordered_map<string,int> skills;
    unordered_map<int,vector<int> > graph;
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int i;
        vector<int> ans;
        unordered_set<int> minim, temp;
        for (i = 0; i < req_skills.size(); i++)
            skills[req_skills[i]] = i;
        for (i = 0; i < people.size(); i++) {
            for (auto &x : people[i]) {
                if (skills.find(x) != skills.end()) 
                    graph[skills[x]].push_back(i);
            }
        }
        for (i = 0; i < people.size(); i++)
            minim.insert(i);
        dfs(0,minim,temp);
        for (auto &x : minim)
            ans.push_back(x);
        return ans;
    }
    
    void dfs(int id, unordered_set<int>& best, unordered_set<int>& path) {
        int i;
        bool present;
        if (id == skills.size()) {
            if (path.size() < best.size()) 
                best = path;
            return;
        }
        if (path.size() >= best.size())
            return;
        for (auto &x : graph[id]) {
            present = path.find(x) != path.end();
            path.insert(x);
            dfs(id+1,best,path);
            if (!present)
                path.erase(x);
        }
    }
};
