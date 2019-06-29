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
    int helper(TreeNode *root, int maxim, int minim) {
        int l, r;
        if (!root)
            return 0;
        if (root->val > maxim)
            maxim = root->val;
        if (root->val < minim)
            minim = root->val;
        l = helper(root->left,maxim,minim);
        r = helper(root->right,maxim,minim);
        return maxim-minim > max(l,r) ? maxim-minim : max(l,r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxim = 0, minim = 100000;
        return helper(root,maxim,minim);
    }
};
