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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        deque<TreeNode *>Q;
        TreeNode *curr;
        int ans = 1,s,i;
        Q.push_back(root);
        while (!Q.empty()) {
            while (Q.size() > 0 && Q.front() == NULL)
                Q.pop_front();
            while(Q.size() > 0 && Q.back() == NULL)
                Q.pop_back();
            s = Q.size();
            if (s == 0)
                break;
            if (s > ans)
                ans = s;
            for (i = 0; i < s; i++) {
                curr = Q.front();
                Q.pop_front();
                if (curr != NULL) {
                    Q.push_back(curr->left);
                    Q.push_back(curr->right);
                }
                else {
                    Q.push_back(NULL);
                    Q.push_back(NULL);
                }
            }
        }
        return ans;
    }
};
