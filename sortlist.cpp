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
    ListNode* splitList(ListNode* head) {
        ListNode *curr = head, *mid, *prevMid = NULL;
        while (curr && curr->next) {
            prevMid = (prevMid) ? prevMid->next : head;
            curr = curr->next->next;
        }
        mid = prevMid->next;
        prevMid->next = NULL;
        return mid;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *sortedList = new ListNode(0);
        ListNode *curr = sortedList;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;    
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = (l1) ? l1 : l2;
        return sortedList->next;
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode *l, *m, *r;
        if (!head || !head->next)
            return head;
        m = splitList(head);
        l = sortList(head);
        r = sortList(m);
        return merge(l, r);
    }
};
