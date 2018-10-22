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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        deque<TreeNode*> nodes;
        bool lTr = true;
        TreeNode *curr;
        int n, i;
        if (root != NULL) {
            nodes.push_back(root);
            while (!nodes.empty()) {
                n = nodes.size();
                vector<int> level;
                for (i = 0; i < n; i++) {
                    if (!lTr) {
                        curr = nodes.back();
                        nodes.pop_back();
                        level.push_back(curr->val);
                        if (curr->right != NULL)
                            nodes.push_front(curr->right);
                        if (curr->left != NULL)
                            nodes.push_front(curr->left);
                    }
                    else {
                        curr = nodes.front();
                        nodes.pop_front();
                        level.push_back(curr->val);
                        if (curr->left != NULL)
                            nodes.push_back(curr->left);
                        if (curr->right != NULL)
                            nodes.push_back(curr->right);
                    }
                }
                lTr = !lTr;
                ans.push_back(level);
            }
        }
        return ans;
    }
};
