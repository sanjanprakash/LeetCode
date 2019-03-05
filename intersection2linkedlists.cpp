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
    int len(ListNode *head) {
        int ans = 0;
        while (head != NULL) {
            head = head->next;
            ans++;
        }
        return ans;
    }
    
    bool aGreater(int a, int b, int &diff) {
        if (a < b)
            diff = b-a;
        else
            diff = a-b;
        return a > b;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a = len(headA), len_b = len(headB);
        ListNode *curr_a = headA, *curr_b = headB;
        int d;
        bool a = aGreater(len_a,len_b,d);
        if (a) {
            while (d > 0) {
                curr_a = curr_a->next;
                d--;
            }
        }
        else {
            while (d > 0) {
                curr_b = curr_b->next;
                d--;
            }
        }
        while (curr_a != NULL) {
            if (curr_a == curr_b)
                break;
            curr_a = curr_a->next;
            curr_b = curr_b->next;
        }
        return curr_a;
    }
};
