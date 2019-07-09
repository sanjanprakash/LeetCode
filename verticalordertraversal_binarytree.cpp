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
private:
    map<int,map<int,vector<int>>> grid;
public:
    void aux(TreeNode *root, int col, int depth) {
        if (root != NULL) {
            grid[col][depth].push_back(root->val);
            if (grid[col][depth].size() > 1)
                sort(grid[col][depth].begin(),grid[col][depth].end());
            aux(root->left,col-1,depth+1);
            aux(root->right,col+1,depth+1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int i;
        map<int,map<int,vector<int>>>::iterator itc;
        map<int,vector<int>>::iterator itr;
        aux(root,0,0);
        vector<vector<int>> ans;
        for (itc = grid.begin(); itc != grid.end(); itc++) {
            vector<int> col;
            for (itr = itc->second.begin(); itr != itc->second.end(); itr++) {
                for (i = 0; i < itr->second.size(); i++)
                    col.push_back(itr->second[i]);
            }
            ans.push_back(col);
        }
        return ans;
    }
};
