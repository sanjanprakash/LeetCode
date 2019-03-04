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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *neo_head = NULL, *temp = NULL, *curr = head->next, *prev = head;
        int c = 1;
        while (curr != NULL) {
            if (curr->val == prev->val)
                c++;
            else {
                if (c < 2) {
                    if (neo_head == NULL) {
                        neo_head = prev;
                        temp = prev;
                    }
                    else {
                        temp->next = prev;
                        temp = temp->next;
                    }
                }
                c = 1;
            }
            prev = curr;
            curr = curr->next;
        }
        if (c < 2) {
            if (neo_head == NULL)
                neo_head = prev;
            else
                temp->next = prev;
        }
        else if (neo_head != NULL)
            temp->next = NULL;
        return neo_head;
    }
};
