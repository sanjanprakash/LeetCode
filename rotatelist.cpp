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
    int length(ListNode *head) {
        int n = 0;
        ListNode *tmp = head;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }
        return n;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0, l = length(head);
        ListNode *A = head, *B = head, *neo;
        if (l)
            k = k%l;
        while (count < k && A) {
            A = A->next;
            count++;
        }
        if (A) {
            while (A->next) {
                A = A->next;
                B = B->next;
            }
            if (B->next) {
                A = B->next;
                neo = A;
                B->next = NULL;
                while (A->next)
                    A = A->next;
                A->next = head;
                head = neo;
            }
        }
        return head;
    }
};
