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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* incr = head;
        int carry = 0;
        int sum = 0;
        ListNode* next_node = NULL;
    
       while (l1 != NULL || l2 != NULL) {
           carry = 0;
           if (l1 != NULL) {
               sum = incr->val + l1->val;
               carry = sum / 10;
               incr->val = sum % 10;
               l1 = l1->next;
           }
           if (l2 != NULL) {
               sum = incr->val + l2->val;
               carry = carry | (sum / 10);
               incr->val = sum % 10;
               l2 = l2->next;
           }           
           if (l1 != NULL || l2 != NULL) {
              next_node = new ListNode(carry);
              incr->next = next_node;
              incr = next_node;
           }
       }
    
    if (carry != 0) {
        next_node = new ListNode(carry);
        incr->next = next_node;
    }
    
    return head;
    }
};
