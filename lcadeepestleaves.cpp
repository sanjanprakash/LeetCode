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
public:
    unordered_map<TreeNode *, int> max_depth;
    unordered_map<int, vector<TreeNode *> > dists;
    int max_d;
    
    int bfs(TreeNode *root, int d) {
        if (root) {
            dists[d].push_back(root);
            max_d = max(max_d,d);
            int l = bfs(root->left,d+1);
            int r = bfs(root->right,d+1);
            max_depth[root] = max(l,r);
            return max_depth[root];
        }
        return d-1;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int cnt = 0;
        int curr_ans = -1;
        TreeNode *ans;
        vector<TreeNode *> valid;
        max_d = INT_MIN;
        bfs(root,0);
        unordered_map<TreeNode *, int>::iterator it;
        for (auto &x : dists) {
            cnt = 0;
            valid.clear();
            for (auto &y : x.second) {
                if (max_depth[y] == max_d) {
                    valid.push_back(y);
                    cnt++;
                }
            }
            if (cnt == 1) {
                if (curr_ans < x.first) {
                    curr_ans = x.first;
                    ans = valid[0];
                }                
            }
        }
        return ans;
    }
};
