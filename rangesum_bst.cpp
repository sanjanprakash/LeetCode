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
    
    int ans = 0;
    
    void Summer(TreeNode *root, int L, int R) {
        if (root != NULL) {
            if (root->val >= L && root->val <= R) {
                ans += root->val;
                Summer(root->left,L,R);
                Summer(root->right,L,R);
            }
            if (root->val < L)
                Summer(root->right,L,R);
            if (root->val > R)
                Summer(root->left,L,R);
        }
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return 0;
        Summer(root,L,R);
        return ans;
    }
};
