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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root != NULL) {
            int largest = INT_MIN, s = 1;
            queue<TreeNode *> Q;
            TreeNode *curr;
            Q.push(root);
            while (!Q.empty()) {
                curr = Q.front();
                largest = max(curr->val,largest);
                Q.pop();
                s--;
                if (curr->left != NULL)
                    Q.push(curr->left);
                if (curr->right != NULL)
                    Q.push(curr->right);
                if (s == 0) {
                    s = Q.size();
                    ans.push_back(largest);
                    largest = INT_MIN;
                }
            }
        }
        return ans;
    }
};
