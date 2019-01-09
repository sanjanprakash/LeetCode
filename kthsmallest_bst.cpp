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
private :
    TreeNode *curr;
public:    
    void levelOrderTillKth(TreeNode *root, int &k) {
        if (root != NULL && k > 0) {
                levelOrderTillKth(root->left,k);
            if (k > 0) {
                curr = root;
                k--;
            }
            levelOrderTillKth(root->right,k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        levelOrderTillKth(root,k);
        return curr->val;
    }
};
