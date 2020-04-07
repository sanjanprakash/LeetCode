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
    void flatten(TreeNode *root, vector<int> &arr) {
        if (root) {
            flatten(root->left, arr);
            arr.push_back(root->val);
            flatten(root->right, arr);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        int i = 0, j = 0;
        vector<int> l1, l2;
        vector<int> ans;
        flatten(root1, l1);
        flatten(root2, l2);
        while (i < l1.size() && j < l2.size()) {
            if (l1[i] <= l2[j]) 
                ans.push_back(l1[i++]);
            else
                ans.push_back(l2[j++]);
            
        }
        while (i < l1.size()) 
            ans.push_back(l1[i++]);       
        while (j < l2.size()) 
            ans.push_back(l2[j++]);
        return ans;
    }
};
