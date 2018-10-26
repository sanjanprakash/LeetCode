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
    TreeNode *prev = NULL;
    int ans = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if (root->left != NULL)
            ans = minDiffInBST(root->left);
        if (prev != NULL)
            ans = min(ans,root->val - prev->val);
        prev = root;
        if (root->right != NULL)
            minDiffInBST(root->right);
        return ans;
    }
};
