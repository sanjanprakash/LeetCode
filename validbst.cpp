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
    bool Checker(TreeNode *root, long &l) {
        if (root == NULL)
            return true;
        if (Checker(root->left,l) == false)
            return false;
        if (root->val <= l)
            return false;
        l = root->val;
        return Checker(root->right,l);
    }
    
    bool isValidBST(TreeNode* root) {
        long l = LONG_MIN;
        return Checker(root,l);        
    }
};
