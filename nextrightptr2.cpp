/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        deque<TreeLinkNode *> Q;
        TreeLinkNode *curr;
        Q.push_back(root);
        int s,i;
        if (root == NULL)
            return;
        while (!Q.empty()) {
            s = Q.size();
            Q.back()->next = NULL;
            for (i = 0; i < s; i++) {
                curr = Q.front();
                Q.pop_front();
                if (i != s-1)
                    curr->next = Q.front();
                if (curr->left != NULL)
                    Q.push_back(curr->left);
                if (curr->right != NULL)
                    Q.push_back(curr->right);
            }
        }
    }
};
