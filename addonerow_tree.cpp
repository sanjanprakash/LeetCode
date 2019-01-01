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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        int level = 1;
        if (d == 1) {
            TreeNode *neo = new TreeNode(v);
            neo->left = root;
            root = neo;
        }
        else {
            queue<TreeNode *> Q;
            Q.push(root);
            TreeNode *curr;
            int i,s;
            while (level < d-1) {
                s = Q.size();
                for (i = 0; i < s; i++) {
                    curr = Q.front();
                    Q.pop();
                    if (curr->left != NULL)
                        Q.push(curr->left);
                    if (curr->right != NULL)
                        Q.push(curr->right);
                }
                level++;
            }
            while (!Q.empty()) {
                TreeNode *neo_l = new TreeNode(v);
                TreeNode *neo_r = new TreeNode(v);
                curr = Q.front();
                Q.pop();
                neo_l->left = curr->left;
                neo_r->right = curr->right;
                curr->left = neo_l;
                curr->right = neo_r;
            }
        }
        return root;
    }
};
