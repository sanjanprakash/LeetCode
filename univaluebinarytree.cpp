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
    bool Check(TreeNode *root, int num) {
        if (root != NULL) {
            if (root->val != num)
                return false;
            return Check(root->left,root->val) & Check(root->right,root->val);
        }
        return true;
    }
    
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL)
            return true;
        return Check(root,root->val);
    }
};
