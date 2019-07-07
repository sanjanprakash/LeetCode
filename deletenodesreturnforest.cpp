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
    void eraser(TreeNode *curr, vector<int>& to_delete, vector<TreeNode *> &forest, TreeNode *par) {
        if (curr) {
            eraser(curr->left,to_delete,forest,curr);
            eraser(curr->right,to_delete,forest,curr);
            if (find(to_delete.begin(),to_delete.end(),curr->val) != to_delete.end()) {
                if (par) {
                    if (par->left == curr)
                        par->left = NULL;
                    else
                        par->right = NULL;
                }
                to_delete.erase(remove(to_delete.begin(), to_delete.end(), curr->val), to_delete.end());
            }
            else if (par == NULL || find(to_delete.begin(),to_delete.end(),par->val) != to_delete.end())
                forest.push_back(curr);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> forest;
        eraser(root,to_delete,forest,NULL);
        return forest;
    }
};
