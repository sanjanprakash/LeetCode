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
    pair<int,int> helper(TreeNode *root) {
        int include, exclude;
        pair<int,int> left, right;
        if (!root)
            return {0,0};
        if (!root->left && !root->right)
            return {root->val,0};
        left = helper(root->left);
        right = helper(root->right);
        exclude = left.first+right.first;
        include = max(exclude,root->val+left.second+right.second);
        return {include,exclude};
    }
    
    int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return ans.first;
    }
};
