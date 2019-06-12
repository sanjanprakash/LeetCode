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
    int finder(TreeNode *root, TreeNode* &par, int h, int val) {
        int l = 0,r = 0;
        if (root) {
            if (root->val == val) 
                return h;
            par = root;
            l = finder(root->left,par,h+1,val);
            if (!l) 
                par = root;
            return l ? l : finder(root->right,par,h+1,val);
        }
        return 0;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int h_x, h_y;
        TreeNode *par_x = NULL, *par_y = NULL;
        h_x = finder(root,par_x,0,x);
        h_y = finder(root,par_y,0,y);
        return h_x && h_y && h_x == h_y && par_x != par_y;
    }
};
