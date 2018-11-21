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
    vector<int>ans;
    
    void RightDown(TreeNode *root, int depth) {
        if (root != NULL) {
            if (depth == ans.size())
                ans.push_back(root->val);
            RightDown(root->right,depth+1);
            RightDown(root->left,depth+1);
        }    
    }
    
    vector<int> rightSideView(TreeNode* root) {
        RightDown(root,0);
        return ans;
    }
};
