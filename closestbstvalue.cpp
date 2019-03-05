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
    void aux(TreeNode *root, int &ans, double target, double &diff) {
        if (root != NULL) {
            if (abs(double(root->val)-target) < diff) {
                diff = abs(double(root->val)-target);
                ans = root->val;
            }
            aux(root->left,ans,target,diff);
            aux(root->right,ans,target,diff);
        }
    }
    
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        double diff = abs(double(ans) - target);
        aux(root,ans,target,diff);
        return ans;
    }
};
