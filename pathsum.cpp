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
    bool ans = false;
    void checker(TreeNode *root, int sum) {
        if (root != NULL) {
            int c = sum - root->val;
            if (root->left == NULL && root->right == NULL && c == 0) 
                    ans = true;
            checker(root->left, c);
            checker(root->right, c);
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        checker(root, sum);
        return ans;
    }
};
