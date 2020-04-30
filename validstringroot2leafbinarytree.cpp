/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode *root, vector<int> &arr, int idx) {
        if (idx == arr.size()-1 && root && root->val == arr[idx] && !(root->left) && !(root->right))
            return true;
        if (idx == arr.size() || !root)
            return false;
        if (root->val != arr[idx])
            return false;
        return helper(root->left, arr, idx+1) || helper(root->right, arr, idx+1);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
         return helper(root, arr, 0);
    }
};
