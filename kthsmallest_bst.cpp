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
    vector<int> nodes;
public:    
    void levelOrderTillKth(TreeNode *root, int k) {
        if (root != NULL && nodes.size() != k) {
            levelOrderTillKth(root->left,k);
            nodes.push_back(root->val);
            levelOrderTillKth(root->right,k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        levelOrderTillKth(root,k);
        return nodes[k-1];
    }
};
