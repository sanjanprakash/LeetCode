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
private:
    int max(int a, int b) {
        return a < b ? b : a;
    }
    
    int diver(int height, TreeNode *root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return height;
        height = max(diver(height+1,root->left),diver(height+1,root->right));
        return height;
    }
    
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return diver(1,root);   
    }
};
