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
    void pathFinder(TreeNode *ptr, vector<string> &paths, string curr) {
        if (ptr) {
            curr = curr + "->" + to_string(ptr->val);
            pathFinder(ptr->left,paths,curr);
            pathFinder(ptr->right,paths,curr);
            if (!ptr->left && !ptr->right)
                paths.push_back(curr);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr;
        vector<string> paths;
        if (root) {
            curr = to_string(root->val);
            pathFinder(root->left,paths,curr);
            pathFinder(root->right,paths,curr);
        }
        if (!paths.size() && root)
            paths.push_back(curr);
        return paths;
    }
};
