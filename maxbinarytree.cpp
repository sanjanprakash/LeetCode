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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        deque<TreeNode*> DQ;
        int i;
        for (i = 0; i < nums.size(); i++) {
            TreeNode *curr = new TreeNode(nums[i]);
            while (!DQ.empty() && DQ.back()->val < nums[i]) {
                curr->left = DQ.back();
                DQ.pop_back();
            }
            if (!DQ.empty())
                DQ.back()->right = curr;
            DQ.push_back(curr);
        }
        return DQ.front();
    }
};
