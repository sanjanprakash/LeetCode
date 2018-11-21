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
    vector<int>nums;
    void summer(int ans, TreeNode *root) {
        if (root != NULL) {
            int num = 10*ans + root->val;
            if (root->left == NULL && root->right == NULL)
                nums.push_back(num);
            else {
                summer(num, root->left);
                summer(num, root->right);
            }
        }    
    }
    int sumNumbers(TreeNode* root) {
        summer(0,root);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += nums[i];
        return ans;
    }
};
