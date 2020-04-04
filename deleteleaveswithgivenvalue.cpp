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
private:
    bool isLeaf(TreeNode *root) {
        if (!root)
            return true;
        return (!root->left && !root->right);
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!isLeaf(root->left))
            root->left = removeLeafNodes(root->left, target);
        if (!isLeaf(root->right))
            root->right = removeLeafNodes(root->right, target);
        if (root->left && isLeaf(root->left) && root->left->val == target) {
            delete(root->left);
            root->left = NULL;
        }
        if (root->right && isLeaf(root->right) && root->right->val == target) {
            delete(root->right);
            root->right = NULL;
        }
        if (isLeaf(root) && root->val == target)
            return NULL;
        return root;
    }
};
