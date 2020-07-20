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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr, *prev = NULL, *tmp;
        while (head && head->val == val) {
            prev = head;
            head = head->next;
            delete prev;
        }
        curr = head;
        prev = NULL;
        while (curr) {
            // cout << curr->val << " ";
            if (curr->val == val) {
                prev->next = curr->next;
                tmp = curr;
                delete tmp;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
