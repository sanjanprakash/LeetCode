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
    void auxSummer(int &sum, int curr_num, TreeNode *root) {
        if (root) {
            curr_num = 2*curr_num + root->val;
            if (root->left)
                auxSummer(sum,curr_num,root->left);
            if (root->right)
                auxSummer(sum,curr_num,root->right);
            else if (!root->left && !root->right)
                sum += curr_num;
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0, num = 0;
        auxSummer(sum,num,root);
        return sum;
    }
};
