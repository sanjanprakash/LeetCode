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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root != NULL) {
            TreeNode *curr = root;
            stack<TreeNode*> S;
            while (curr != NULL) {
                S.push(curr);
                curr = curr->left;
            }
            while (!S.empty()) {
                curr = S.top();
                S.pop();
                ans.push_back(curr->val);
                curr = curr->right;
                while (curr != NULL) {
                    S.push(curr);
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};
