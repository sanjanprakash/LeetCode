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
    int helper(TreeNode *root, int &best) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL) {
            best = max(root->val, best);
            return root->val;
        }
        int left = helper(root->left, best);
        int right = helper(root->right, best);
        best = max(left + root->val + right, best);
        best = max(left + root->val, best);
        best = max(root->val + right, best);
        best = max(root->val, best);
        return max(root->val + max(left, right), root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return root ? ans : 0;
    }
};
