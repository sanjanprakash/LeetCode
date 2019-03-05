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
    bool aux(TreeNode *root, long l, long r) {
        if (root == NULL)
            return true;
        if (root->val <= l || root->val >= r)
            return false;
        return aux(root->left,l,root->val) && aux(root->right,root->val,r);
    }
    
    bool isValidBST(TreeNode* root) {
        long l = LONG_MIN;
        long r = LONG_MAX;
        return aux(root,l,r);    
    }
};
