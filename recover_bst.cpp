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
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        vector<TreeNode *> nodes;
        Inorder(nums,nodes,root);
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++)
            nodes[i]->val = nums[i];
    }
    
    void Inorder(vector<int>& nums, vector<TreeNode *>& nodes, TreeNode *root) {
        if (root != NULL) {
            Inorder(nums,nodes,root->left);
            nums.push_back(root->val);
            nodes.push_back(root);
            Inorder(nums,nodes,root->right);
        }
    }
};
