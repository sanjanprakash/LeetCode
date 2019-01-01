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
    int Height(bool left, TreeNode *root) {
        int h = 0;
        if (left) {
            while (root != NULL) {
                root = root->left;
                h++;
            }
        }
        else {
            while (root != NULL) {
                root = root->right;
                h++;
            }
        }
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if (root != NULL) {
            int l = Height(true,root);
            int r = Height(false,root);
            if (l == r)
                return pow(2,l)-1;
            else
                return 1 + countNodes(root->left) + countNodes(root->right);
        }
        return 0;
    }
};
