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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0, s;
        TreeNode* curr;
        deque<TreeNode*> q;
        if (root) {
            q.push_back(root);
            while (!q.empty()) {
                while (!q.empty() && !q.front())
                    q.pop_front();
                while (!q.empty() && !q.back())
                    q.pop_back();
                s = q.size();
                ans = max(ans, s);
                while (s--) {
                    curr = q.front();
                    q.pop_front();
                    if (curr) {
                        q.push_back(curr->left);
                        q.push_back(curr->right);
                    }
                    else {
                        q.push_back(NULL);
                        q.push_back(NULL);
                    }
                }
            }
        }
        return ans;
    }
};
