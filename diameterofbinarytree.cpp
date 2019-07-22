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
    int maxFinder(TreeNode *root, int level, int &ans) {
        int l, r;
        if (!root || (!root->left && !root->right))
            return 0;
        l = maxFinder(root->left,level+1,ans);
        r = maxFinder(root->right,level+1,ans);
        if (root->left)
            l++;
        if (root->right)
            r++;
        ans = max(ans,l+r);
        return max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        maxFinder(root,0,ans);
        return ans == INT_MIN ? 0 : ans;
    }
};
