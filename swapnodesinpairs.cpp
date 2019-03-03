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
    ListNode* swapPairs(ListNode* head) {
        if (head != NULL && head->next != NULL) {
            ListNode *tmp = head;
            ListNode *remainder = head->next->next;
            head = head->next;
            head->next = tmp;
            tmp->next = swapPairs(remainder);
        }
        return head;
    }
};
