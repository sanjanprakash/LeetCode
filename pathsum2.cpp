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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector <int> > ans;
        vector<int> inst;
        if (root != NULL)
            Traverse(root, 0, sum, ans, inst);
        return ans;
    }
    
    void Traverse(TreeNode* root, int curr_sum, int sum, vector<vector <int> >& ans, vector<int>& inst) {
        if (root == NULL) {
            inst.push_back(0);
            return;
        }
        else {
            inst.push_back(root->val);
            curr_sum += root->val;
            if (root->left == NULL && root->right == NULL && curr_sum == sum) {
                ans.push_back(inst);
                return;
            }
            Traverse(root->left, curr_sum, sum, ans, inst);
            inst.pop_back();
            Traverse(root->right, curr_sum, sum, ans, inst);
            inst.pop_back();
        }
        
    }
};
