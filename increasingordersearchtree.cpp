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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *up = root, *down = root, *prev = NULL;
        while (up) {
            while (up->left) {
                down = up->left;
                up->left = down->right;
                down->right = up;
                up = down;
            }
            if (prev)
                prev->right = up;
            else
                root = up;
            prev = up;            
            up = up->right;
        }
        return root;
    }
};
