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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0, seen, done = 0;
        ListNode *move = head;
        ListNode *prev = head, *curr, *succ;
        ListNode *temp_head, *prev_tail = NULL;
        while (move) {
            move = move->next;
            cnt++;
        }
        if (cnt == 2 && k == 2) {
            curr = head->next;
            curr->next = prev;
            prev->next = NULL;
            head = curr;
            
        }
        else if (k > 1 && cnt > 2) {
            curr = head->next;
            succ = head->next->next;
            while (done < cnt/k) {
                seen = 1;
                temp_head = prev;
                while (seen < k && succ) {
                    curr->next = prev;
                    prev = curr;
                    curr = succ;
                    succ = succ->next;
                    seen++;
                }
                if (seen < k) {
                    curr->next = prev;
                    prev = curr;
                    curr = succ;
                }
                if (done == 0)
                    head = prev;
                else
                    prev_tail->next = prev;
                prev_tail = temp_head;
                temp_head->next = curr;
                prev = curr;
                if (curr)
                    curr = curr->next;
                if (succ)
                    succ = succ->next;
                done++;
            }
        }
        return head;
    }
};
