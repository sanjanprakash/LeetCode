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
    TreeNode *aux(vector<int> arr, int &ind, int l, int r) {
        if (ind >= arr.size() || (arr[ind] < l) || (arr[ind] > r))
            return NULL;
        else {
            TreeNode *root = new TreeNode(arr[ind]);
            ind++;
            root->left = aux(arr,ind,l,root->val);
            root->right = aux(arr,ind,root->val,r);
            return root;
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return aux(preorder,ind,INT_MIN,INT_MAX);
    }
};
