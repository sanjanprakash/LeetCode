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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt = n-m+1, d = 1;
        ListNode *move = head, *l = head, *r;
        ListNode *prev, *curr, *succ;
        if (n-m) {
            while (d < m-1) {
                l = l->next;
                d++;
            }
            r = l;
            while (d < n+1) {
                r = r->next;
                d++;
            }
            prev = m == 1 ? head : l->next;
            curr = prev ? prev->next : NULL;
            succ = curr ? curr->next : NULL;
            prev->next = r;
            if (n-m == 1) {
                curr->next = prev;
                prev = curr;
            }
            else {
                d = 1;
                while (d < cnt && succ) {
                    curr->next = prev;
                    prev = curr;
                    curr = succ;
                    succ = succ->next;
                    d++;
                }
                if (d < cnt) {
                    curr->next = prev;
                    prev = curr;
                }
            }
            if (m == 1)
                head = prev;
            else
                l->next = prev;
        }
        return head;
    }
};
