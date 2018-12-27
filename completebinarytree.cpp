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
    
    bool Pow2(int n, int exp) {
        while (exp > 0) {
            exp--;
            n /= 2;
        }
        return n == 1 ? true : false;
    }
    
    bool isCompleteTree(TreeNode* root) {
        vector<vector<int> >X;
        queue<TreeNode*> Q;
        TreeNode *curr;
        bool flag = true;
        Q.push(root);
        int i,s;
        while (!Q.empty()) {
            vector<int> level;
            flag = true;
            s = Q.size();
            for (i = 0; i < s; i++) {
                curr = Q.front();
                Q.pop();
                level.push_back(curr->val);
                if (curr->left != NULL) {
                    if (flag)
                        Q.push(curr->left);
                    else
                        return false;
                }
                else
                    flag = false;
                if (curr->right != NULL) {
                    if (flag)
                        Q.push(curr->right);    
                    else
                        return false;
                }
                else
                    flag = false;
            }
            X.push_back(level);       
        }
        for (i = 1; i < X.size()-1; i++) {
            if (!Pow2(X[i].size(),i))
                return false;
        }
        return true;
    }
};
