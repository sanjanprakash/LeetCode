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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> S;
        unordered_map<TreeNode *,int> X;
        TreeNode *curr;
        if (root != NULL) {
            S.push(root);
            while (!S.empty()) {
                curr = S.top();
                if (curr->left != NULL && X[curr->left] == 0) {
                    S.push(curr->left);
                    X[curr->left] = 1;
                }
                else if (curr->right != NULL && X[curr->right] == 0) {
                    S.push(curr->right);
                    X[curr->right] = 1;
                }
                else {
                    ans.push_back(curr->val);
                    S.pop();
                }
            }
        }
        return ans;
    }
};
