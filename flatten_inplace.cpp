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
    TreeNode *curr;
    void flatten(TreeNode* root) {
        if (root != NULL) {
            curr = root;
            flatten(root->left);
            if (root->right != NULL) {
                curr->right = root->right;
                if (curr != root) 
                    root->right = NULL;
                flatten(curr->right);
            }
            if (root->left != NULL) {
                root->right = root->left;
                root->left = NULL;
            }
        }     
    }
};
