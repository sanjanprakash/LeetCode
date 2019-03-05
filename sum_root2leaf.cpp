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
    void treeSummer(TreeNode *root, int &sum, int num) {
        if (root != NULL) {
            num = (num*10) + root->val;
            if (root->left == NULL && root->right == NULL)
                sum += num;
            treeSummer(root->left,sum,num);
            treeSummer(root->right,sum,num);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        treeSummer(root,ans,0);
        return ans;
    }
};
