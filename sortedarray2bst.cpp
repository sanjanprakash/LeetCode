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
    TreeNode *auxBuilder(vector<int> arr, int l, int r) {
        int m;
        if (l > r)
            return NULL;
        m = (l+r)/2;
        if ((l+r)%2)
            m++;
        TreeNode *root = new TreeNode(arr[m]);
        root->left = auxBuilder(arr,l,m-1);
        root->right = auxBuilder(arr,m+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return auxBuilder(nums,0,nums.size()-1);
    }
};
