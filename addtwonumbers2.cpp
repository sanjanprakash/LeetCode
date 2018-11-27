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
    ListNode* Adder(int n1, int n2, ListNode *l1, ListNode *l2, int &carry) {
        if (n1 == 0 && n2 == 0)
            return NULL;
        if (n1 > n2) {
            ListNode *curr_solo = Adder(n1-1,n2,l1->next,l2,carry);
            ListNode *neo = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry)/10;
            neo->next = curr_solo;
            return neo;
        }
        ListNode *curr_both = Adder(n1-1,n2-1,l1->next,l2->next,carry);
        ListNode *neo = new ListNode((l1->val + l2->val + carry) % 10);
        carry = (l1->val + l2->val + carry)/10;
        neo->next = curr_both;
        return neo;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        int n1 = 0,n2 = 0;
        ListNode *ptr = l1;
        ListNode *ptr1 = l1, *ptr2 = l2;
        while (ptr != NULL) {
            ptr = ptr->next;
            n1++;
        }
        ptr = l2;
        while (ptr != NULL) {
            ptr = ptr->next;
            n2++;
        }
        if (n1 <= n2) {
            ans = Adder(n2,n1,ptr2,ptr1,carry);
            if (carry == 1) {
                ListNode *neo = new ListNode(1);
                neo->next = ans;
                return neo;
            }
            return ans;
        }
        else {
            ans = Adder(n1,n2,ptr1,ptr2,carry);
            if (carry == 1) {
                ListNode *neo = new ListNode(1);
                neo->next = ans;
                return neo;
            }
            return ans;
        }
    }
};
