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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c1 = 0,c2 = 0;
        ListNode *find,*bait = head,*prev = NULL;
        while (c1 != n) {
            bait = bait->next;
            c1++;
        }
        if (bait == NULL) 
            head = head->next;
        else {
            find = head;
            while (bait != NULL) {
                bait = bait->next;
                prev = find;
                find = find->next;
            }
            prev->next = find->next;
        }
        return head;
    }
};
