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
    vector<vector<int>> levelOrder(Node* root) {
        int i, j, size;
        vector<vector<int>> ans;
        queue<Node *> level;
        Node *curr;
        if (root) {
            level.push(root);
            while (!level.empty()) {
                vector<int> uno_level;
                size = level.size();
                j = 0;
                while (j < size) {
                    curr = level.front();
                    level.pop();
                    if (curr) {
                        uno_level.push_back(curr->val);
                        for (i = 0; i < curr->children.size(); i++) {
                            level.push(curr->children[i]);
                        }
                    }
                    j++;
                }
                ans.push_back(uno_level);
            }
        }
        return ans;
    }
};
