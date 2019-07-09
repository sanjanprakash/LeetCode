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
    bool hasCycle(ListNode *head) {
        ListNode *curr = head, *fast = head;
        if (!curr)
            return false;
        while (fast->next && fast->next->next) {
            curr = curr->next;
            fast = fast->next->next;
            if (curr == fast)
                return true;
        }
        return false;
    }
};
