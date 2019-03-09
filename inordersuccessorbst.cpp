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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *ans = NULL;
        if (p->right != NULL) {
            ans = p->right;
            while (ans->left != NULL)
                ans = ans->left;
        }
        else {
            while (root != NULL && root->val != p->val) {
                if (root->val > p->val) {
                    ans = root;
                    root = root->left;
                }
                else
                    root = root->right;
            }
        }
        return ans;
    }
};
