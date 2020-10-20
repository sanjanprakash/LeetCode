/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void helper(Node* clone, Node* original, unordered_map<int, Node*>& all_nodes) {
        for (Node *nbr : original->neighbors) {
            if (!all_nodes[nbr->val]) {
                Node *nbr_clone = new Node(nbr->val);
                all_nodes[nbr->val] = nbr_clone;
                helper(all_nodes[nbr->val], nbr, all_nodes);
            }
            clone->neighbors.push_back(all_nodes[nbr->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> all_nodes;
        Node *clone;
        if (!node)
            return NULL;
        clone = new Node(node->val);
        all_nodes[node->val] = clone;
        helper(clone, node, all_nodes);
        return clone;
    }
};
