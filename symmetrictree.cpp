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
    bool aux(TreeNode *l, TreeNode *r) {
        if (l == NULL && r == NULL)
            return true;
        if (l == NULL || r == NULL)
            return false;
        if (l->val != r->val)
            return false;
        return aux(l->left,r->right) == false ? false : aux(l->right,r->left);
            
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return aux(root->left,root->right);
    }
};
