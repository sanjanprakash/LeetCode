/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        int s = 1;
        Node *curr;
        queue<Node *> Q;
        if (root) {
            Q.push(root);
            while (!Q.empty()) {
                while (s--) {
                    curr = Q.front();
                    Q.pop();
                    curr->next = (s)? Q.front() : NULL;
                    if (curr->left) {
                        Q.push(curr->left);
                        Q.push(curr->right);
                    }
                }
                s = Q.size();
            }
        }
        return root;
    }
};
