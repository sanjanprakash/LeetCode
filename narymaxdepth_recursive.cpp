/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int i;
        int temp, max = 0;
        if (root) {
            for (i = 0; i < root->children.size(); i++) {
                if (root->children[i]) {
                    temp = maxDepth(root->children[i]);
                    if (temp > max)
                        max = temp;
                }
            }
            return max+1;
        }
        return 0;
    }
};
