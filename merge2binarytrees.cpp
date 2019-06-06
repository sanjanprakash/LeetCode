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
    TreeNode *auxMerger(TreeNode *r1, TreeNode *r2) {
        if (r1 && !r2)
            return r1;
        if (!r1 && r2)
            return r2;
        if (!r1 && !r2)
            return NULL;
        else {
            r1->val += r2->val;
            r1->left = auxMerger(r1->left,r2->left);
            r1->right = auxMerger(r1->right,r2->right);
            return r1;
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return auxMerger(t1,t2);
    }
};
