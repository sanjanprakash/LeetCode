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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *left, *right;
        if (root == NULL || root == p || root == q)
            return root;
        left = lowestCommonAncestor(root->left,p,q);
        right = lowestCommonAncestor(root->right,p,q);
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        return root;
    }
};
