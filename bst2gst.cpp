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
    TreeNode* auxSummer(TreeNode *root, int &sum) {
        if (root) {
            if (!root->left && !root->right) {
                sum += root->val;
                root->val = sum;
            }
            else {
                root->right = auxSummer(root->right,sum);
                sum += root->val;
                root->val = sum;
                root->left = auxSummer(root->left,sum);
            }
        }
        return root;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        return auxSummer(root,sum);    
    }
};
