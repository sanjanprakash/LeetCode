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
    void helper(TreeNode* root, int depth, int& min_depth) {
        if (root) {
            if (!root->left && !root->right)
                min_depth = min(min_depth, depth);
            helper(root->left, depth+1, min_depth);
            helper(root->right, depth+1, min_depth);
        }
    }
    
    int minDepth(TreeNode* root) {
        int min_depth = INT_MAX;
        if (!root)
            return 0;
        helper(root, 0, min_depth);
        return min_depth+1;
    }
};
