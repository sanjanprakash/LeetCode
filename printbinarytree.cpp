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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string> > ans;
        vector<vector<string> > levels;
        vector<string> temp;
        queue<TreeNode*> Q;
        TreeNode *curr;
        int i,j,k,s;
        int start,gap,next;
        int nulls;
        if (root != NULL) {
            Q.push(root);
            while (1) {
                s = Q.size();
                nulls = 0;                
                for (i = 0; i < s; i++) {
                    curr = Q.front();
                    Q.pop();
                    if (curr != NULL) {
                        temp.push_back(to_string(curr->val));
                        Q.push(curr->left);
                        Q.push(curr->right);
                    }
                    else {
                        nulls++;
                        temp.push_back("");
                        Q.push(NULL);
                        Q.push(NULL);
                    }
                }
                if (nulls > 0 && nulls == temp.size())
                    break;
                levels.push_back(temp);
                temp.clear();
            }
            start = (s-1)/2;
            gap = s;
            for (i = 0; i < levels.size(); i++) {
                next = start;
                temp.clear();
                j = 0;
                for (k = 0; k < s-1; k++) {
                    if (k == next) {
                        temp.push_back(levels[i][j]);
                        j++;
                        next += gap;
                    }
                    else
                        temp.push_back("");
                }
                ans.push_back(temp);
                gap /= 2;
                start /= 2;
            }
        }
        return ans;
    }
};
