/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode *root_ptr;
    CBTInserter(TreeNode* root) {
        root_ptr = root;
    }
    
    int insert(int v) {
        TreeNode *curr, *neo;
        neo = new TreeNode(v);
        queue<TreeNode *> Q;
        Q.push(root_ptr);
        int i, s;
        while (!Q.empty()) {
            s = Q.size();
            for (i = 0; i < s; i++) {
                curr = Q.front();
                Q.pop();
                if (curr->left == NULL) {
                    curr->left = neo;
                    return curr->val;
                }
                else
                    Q.push(curr->left);
                if (curr->right == NULL) {
                    curr->right = neo;
                    return curr->val;
                }
                else
                    Q.push(curr->right);
            }
        }
    }
    
    TreeNode* get_root() {
        return root_ptr;    
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
