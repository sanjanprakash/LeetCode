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
    vector<vector<int> > levelOrderTraversal(TreeNode *root) {
        int i, size;
        queue<TreeNode *> Q;
        TreeNode *curr;
        vector<vector<int> > ans;
        if (root) {
            Q.push(root);
            while (!Q.empty()) {
                size = Q.size();
                vector<int> uno_level;
                for (i = 0; i < size; i++) {
                    curr = Q.front();
                    Q.pop();
                    uno_level.push_back(curr->val);
                    if (curr->left)
                        Q.push(curr->left);
                    if (curr->right)
                        Q.push(curr->right);
                }
                ans.push_back(uno_level);
            }
        }
        return ans;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        int i, j;
        double sum;
        vector<double> ans;
        vector<vector<int> > all_levels = levelOrderTraversal(root);
        for (i = 0; i < all_levels.size(); i++) {
            sum = 0.0;
            for (j = 0; j < all_levels[i].size(); j++) {
                sum += double(all_levels[i][j]);
            }
            ans.push_back(sum/double(all_levels[i].size()));
        }
        return ans;
    }
};
