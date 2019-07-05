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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l = new ListNode(0), *g = new ListNode(0);
        ListNode *lesser = l, *greater = g;
        ListNode *curr = head, *ans;
        while (curr) {
            if (curr->val < x) {
                lesser->next = curr;
                lesser = curr;                 
            }
            else {
                greater->next = curr;
                greater = curr;
            }
            curr = curr->next;
        }        
        lesser->next = g->next;
        greater->next = NULL;
        ans = l->next;
        delete l;
        delete g;
        return ans;
    }
};
