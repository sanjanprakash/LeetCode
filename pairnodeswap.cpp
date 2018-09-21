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
        ListNode *move = head;
        int temp;
        while (move != NULL && move->next != NULL) {
            temp = move->val;
            move->val = move->next->val;
            move->next->val = temp;
            move = move->next->next;
        }
        return head;
    }
};
