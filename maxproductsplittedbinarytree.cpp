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
    long long int subtreeSum(TreeNode *root, vector<long long int> &sums) {
        if (!root)
            return 0;
        sums.push_back(subtreeSum(root->left, sums) + root->val + subtreeSum(root->right, sums));
        return sums[sums.size()-1];
    }
    
    int maxProduct(TreeNode* root) {
        long long int i, totalSum;
        long long int ans = -1;
        vector<long long int> subtreeSums;
        totalSum = subtreeSum(root, subtreeSums);
        for (i = 0; i < subtreeSums.size()-1; i++) 
            ans = max(ans, subtreeSums[i]*(totalSum-subtreeSums[i]));   
        return ans%1000000007;
    }
};
