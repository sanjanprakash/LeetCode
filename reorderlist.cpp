/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int n, done = 1;
        ListNode *curr = head, *nextCurr;
        stack<ListNode *> allNodes;
        while (curr) {
            allNodes.push(curr);
            curr = curr->next;
        }
        n = allNodes.size();
        curr = head;
        while (done < n) {
            nextCurr = curr->next;
            curr->next = allNodes.top();
            allNodes.pop();
            curr->next->next = (n-done == 1) ? NULL : nextCurr;
            curr = nextCurr;
            done += 2;
        }
        if (done == n)
            curr->next = NULL;
    }
};
