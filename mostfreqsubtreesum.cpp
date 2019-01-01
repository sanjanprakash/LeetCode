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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if (root != NULL) {
            queue<TreeNode *>Q;
            stack<TreeNode *>S;
            Q.push(root);
            int i,s;
            int max = -1;
            TreeNode *curr;
            unordered_map<int,int>M;
            while (!Q.empty()) {
                s = Q.size();
                for (i = 0; i < s; i++) {
                    curr = Q.front();
                    Q.pop();
                    S.push(curr);
                    if (curr->left != NULL)
                        Q.push(curr->left);
                    if (curr->right != NULL)
                        Q.push(curr->right);
                }
            }
            while (!S.empty()) {
                curr = S.top();
                if (curr->left == NULL && curr->right == NULL)
                    M[curr->val]++;
                else {
                    if (curr->left != NULL)
                        curr->val += curr->left->val;
                    if (curr->right != NULL)
                        curr->val += curr->right->val;
                    M[curr->val]++;
                }
                S.pop();
            }

            for (auto& x: M) {
                if (x.second >= max) {
                    if (x.second > max) {
                        ans.clear();    
                        max = x.second;
                    }
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    }
};
