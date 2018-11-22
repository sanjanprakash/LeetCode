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
    int root_id = 0;
        
    TreeNode *Builder(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (root_id == preorder.size() || start > end)
            return NULL;
        TreeNode *root = new TreeNode(preorder[root_id]);
        int i = 0;
        while (inorder[i] != preorder[root_id])
            i++;
        root_id++;
        root->left = Builder(preorder,inorder,start,i-1);
        root->right = Builder(preorder,inorder,i+1,end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return Builder(preorder,inorder,0,n-1);
    }
};
