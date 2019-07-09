/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *curr = head, *fast = head;
        while (fast->next && fast->next->next) {
            curr = curr->next;
            fast = fast->next->next;
            if (fast == curr)
                break;
        }
        if (!(fast->next) || !(fast->next->next))
            return NULL;
        curr = head;
        while (curr != fast) {
            curr = curr->next;
            fast = fast->next;
        }
        return curr;
    }
};
