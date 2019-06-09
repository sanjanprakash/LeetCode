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
    void auxConverter(TreeNode *root, int &cum_sum) {
        if (root) {
            auxConverter(root->right,cum_sum);
            root->val += cum_sum;
            cum_sum = root->val;
            auxConverter(root->left,cum_sum);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        auxConverter(root,sum);
        return root;
    }
};
