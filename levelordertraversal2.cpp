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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int i, size;
        TreeNode *curr;
        vector<vector<int> > ans;
        queue<TreeNode *> Q;
        if (root) {
            Q.push(root);
            while (!Q.empty()) {
                size = Q.size();
                vector<int> uno_level;
                for (i = 0; i < size; i++) {
                    curr = Q.front();
                    Q.pop();
                    uno_level.push_back(curr->val);
                    if (curr->left)
                        Q.push(curr->left);
                    if (curr->right)
                        Q.push(curr->right);
                }
                ans.insert(ans.begin(),uno_level);
            }
        }
        return ans;
    }
};
