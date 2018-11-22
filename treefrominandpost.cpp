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
    int root_id;
        
    TreeNode *Builder(vector<int>& postorder, vector<int>& inorder, int start, int end) {
        if (root_id < 0 || start > end)
            return NULL;
        TreeNode *root = new TreeNode(postorder[root_id]);
        int i = 0;
        while (inorder[i] != postorder[root_id])
            i++;
        root_id--;
        root->right = Builder(postorder,inorder,i+1,end);
        root->left = Builder(postorder,inorder,start,i-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        root_id = n-1;
        return Builder(postorder,inorder,0,n-1);
    }
};
