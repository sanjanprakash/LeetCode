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
    int maxLevelSum(TreeNode* root) {
        int ans, level = 1, size;
        int sum, max_sum = INT_MIN;
        queue<TreeNode *> Q;
        TreeNode *curr;
        Q.push(root);
        while (!Q.empty()) {
            size = Q.size();
            sum = 0;
            while (size--) {
                curr = Q.front();
                sum += curr->val;
                Q.pop();
                if (curr->left)
                    Q.push(curr->left);
                if (curr->right)
                    Q.push(curr->right);
            }
            if (sum > max_sum) {
                max_sum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
