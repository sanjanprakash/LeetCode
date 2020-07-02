/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int s;
        TreeNode *curr;
        queue<TreeNode *> q;
        stack<vector<int>> allLevels;
        vector<int> level;
        vector<vector<int>> ans;
        
        if (root) {
            s = 1;
            q.push(root);
            while (!q.empty()) {
                while (s--) {
                    curr = q.front();
                    q.pop();
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                    level.push_back(curr->val);
                }
                allLevels.push(level);
                level.clear();
                s = q.size();
            }
            while (!allLevels.empty()) {
                ans.push_back(allLevels.top());
                allLevels.pop();
            }
        }
        
        return ans;
    }
};
