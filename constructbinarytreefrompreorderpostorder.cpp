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
    TreeNode *aux(vector<int> pre, vector<int> post, int &ind, int end) {
        int i = 0;
        if (ind >= pre.size())
            return NULL;
        while (i < end && post[i] != pre[ind])
            i++;
        if (i == end)
            return NULL;
        TreeNode *root = new TreeNode(pre[ind]);
        ind++;
        root->left = aux(pre,post,ind,i);
        root->right = aux(pre,post,ind,i);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int ind = 0;
        return aux(pre,post,ind,post.size());
    }
};
