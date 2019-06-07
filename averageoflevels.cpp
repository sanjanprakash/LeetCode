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
    vector<double> averageOfLevels(TreeNode* root) {
        int i, size;
        double sum;
        TreeNode *curr;
        vector<double> ans;
        queue<TreeNode *> Q;
        if (root) {
            Q.push(root);
            while (!Q.empty()) {
                size = Q.size();
                sum = 0;
                for (i = 0; i < size; i++) {
                    curr = Q.front();
                    Q.pop();
                    sum += double(curr->val);
                    if (curr->left)
                        Q.push(curr->left);
                    if (curr->right)
                        Q.push(curr->right);
                }
                ans.push_back(sum/double(size));
            }
        }
        return ans;
    }
};
