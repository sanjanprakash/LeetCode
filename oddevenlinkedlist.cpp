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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *odd_head = head, *even_head = head->next;
        ListNode *curr_odd = head, *curr_even = head->next;
        ListNode *prev_odd;
        while (curr_even && curr_odd) {
            curr_odd->next = curr_even->next;
            prev_odd = curr_odd;
            curr_odd = curr_odd->next;
            if (curr_odd)
                curr_even->next = curr_odd->next;
            curr_even = curr_even->next;
        }
        if (curr_odd)
            curr_odd->next = even_head;
        else
            prev_odd->next = even_head;
        return odd_head;
    }
};
