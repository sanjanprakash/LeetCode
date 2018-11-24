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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        queue<TreeNode *> Q;
        if (root != NULL) {
            vector<int> level;
            TreeNode *curr;
            int s = 1;
            Q.push(root);
            while (!Q.empty()) {
                curr = Q.front();
                Q.pop();
                level.push_back(curr->val);
                s--;
                if (curr->left != NULL)
                    Q.push(curr->left);
                if (curr->right != NULL)
                    Q.push(curr->right);
                if (s == 0) {
                    s = Q.size();
                    ans.push_back(level);
                    level.clear();
                }
            }
        }
        return ans;
    }
};
