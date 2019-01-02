/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *curr; 
    stack<TreeNode *> S;
public:
    BSTIterator(TreeNode* root) {
        if (root != NULL) {
            curr = root;
            S.push(root);
            while (curr->left != NULL) {
                curr = curr->left;
                S.push(curr);
            }
            curr = S.top();
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int ans;
        ans = curr->val;
        S.pop();
        if (curr->right != NULL) {
            curr = curr->right;
            S.push(curr);
            while (curr->left != NULL) {
                curr = curr->left;
                S.push(curr);
            }
        }
        if (hasNext())
            curr = S.top();
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
