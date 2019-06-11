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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *neo = new TreeNode(val), *temp = root, *prev;
        if (val > root->val) {
            neo->left = root;
            root = neo;
        }
        else {
            while (temp && temp->val > val) {
                prev = temp;
                temp = temp->right;
            }
            prev->right = neo;
            neo->left = temp;
        }
        return root;
    }
};
