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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> ans;
        TreeNode *curr;
        if (root != NULL) {
            S.push(root);
            while (!S.empty()) {
                curr = S.top();
                S.pop();
                if (curr->right != NULL)
                    S.push(curr->right);
                if (curr->left != NULL)
                    S.push(curr->left);
                ans.push_back(curr->val);
            }
        }
        return ans;
    }
};
