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
    void inorder(TreeNode *root, vector<int> &arr) {
        if (root) {
            inorder(root->left,arr);
            if (root->left == NULL && root->right == NULL)
                arr.push_back(root->val);
            inorder(root->right,arr);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int i;
        vector<int> t1, t2;
        inorder(root1,t1);
        inorder(root2,t2);
        if (t1.size() != t2.size())
            return false;
        for (i = 0; i < t1.size(); i++) {
            if (t1[i] != t2[i])
                return false;
        }
        return true;
    }
};
