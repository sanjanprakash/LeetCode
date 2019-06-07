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
    void aux(vector<int> &arr, Node *root) {
        int i;
        if (root) {
            arr.push_back(root->val);
            for (i = 0; i < root->children.size(); i++) 
                aux(arr,root->children[i]);
        }    
    }
    
    vector<int> preorder(Node* root) {
        vector<int> arr;
        aux(arr,root);
        return arr;
    }
};
