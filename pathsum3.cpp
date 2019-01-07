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
public :    
    int pathSum(TreeNode* root, int sum) {
        int root_count = 0;
        if (root == NULL)
            return 0;
        fromRoot(root,root_count,sum);
        return pathSum(root->left,sum) + root_count + pathSum(root->right,sum);
    }
    
    void fromRoot(TreeNode *root, int &count, int sum) {
        if (sum == root->val) 
                count++;
        if (root->left != NULL)
            fromRoot(root->left,count,sum - root->val);
        if (root->right != NULL)
            fromRoot(root->right,count,sum - root->val);
    }    
};
