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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *l, *r;
        if (!cloned)
            return NULL;
        if (cloned->val == target->val)
            return cloned;
        l = getTargetCopy(original, cloned->left, target);
        r = getTargetCopy(original, cloned->right, target);
        return l ? l : r;
    }
};
