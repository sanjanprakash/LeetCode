/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:    
    Node* flatten(Node* head) {
        Node *curr = head, *child_end, *nxt;
        while (curr != NULL) {
            if (curr->child != NULL) {
                nxt = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                child_end = curr->child;
                curr->child = NULL;
                while (child_end->next != NULL)
                    child_end = child_end->next;
                child_end->next = nxt;
                if (nxt != NULL)
                    nxt->prev = child_end;
            }
            curr = curr->next;
        }
        return head;    
    }
};
