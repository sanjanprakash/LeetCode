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
    int sum(TreeNode *root) {
        if (!root)
            return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    
    int findTilt(TreeNode* root) {
        if (!root || (root->left == NULL && root->right == NULL))
            return 0;
        return findTilt(root->left) + findTilt(root->right) + abs(sum(root->left)-sum(root->right));
    }
};
