/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int,vector<int> > graph;
public:
    void graphBuild(TreeNode *curr, TreeNode *par) {
        if (curr) {
            graphBuild(curr->left,curr);
            graphBuild(curr->right,curr);
            if (par) {
                graph[curr->val].push_back(par->val);
                graph[par->val].push_back(curr->val);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        pair<int,int> pred;
        vector<int> ans;
        vector<bool> visited(501,false);
        queue<pair<int,int> > Q;
        graphBuild(root,NULL);
        Q.push({target->val,0});
        visited[target->val] = true;
        while (!Q.empty()) {
            pred = Q.front();
            Q.pop();
            if (pred.second == K) {
                ans.push_back(pred.first);
                continue;
            }
            for (auto adj : graph[pred.first]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    Q.push({adj,pred.second+1});
                }
            }
        }
        return ans;
    }
};
