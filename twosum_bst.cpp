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
    TreeNode* search(TreeNode *root, int val) {
        if (root != NULL) {
            if (root->val == val)
                return root;
            TreeNode *left_res = search(root->left,val);
            if (left_res != NULL)
                return left_res;
            return search(root->right,val);
        }
        return NULL;
    }
    
    bool aux(TreeNode *root, TreeNode *curr, int k) {
        if (root != NULL && curr != NULL) {
            if (search(root,k-curr->val) != NULL && search(root,k-curr->val) != curr)
                return true;
            return aux(root,curr->left,k) || aux(root,curr->right,k);
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        return aux(root,root,k);
    }
};
