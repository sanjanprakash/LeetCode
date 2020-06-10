class Solution {
public:
    void helper(vector<vector<int>>& graph, int start, int end, vector<int> currPath, vector<vector<int> > &allPaths) {
        if (start == end) {
            allPaths.push_back(currPath); 
            return;
        }
        for (int &nbr : graph[start]) {
            currPath.push_back(nbr);
            helper(graph, nbr, end, currPath, allPaths);
            currPath.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> onePath(1, 0);
        vector<vector<int> > ans;
        helper(graph, 0, n-1, onePath, ans);
        return ans;
    }
};
