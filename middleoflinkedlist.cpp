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
    ListNode* middleNode(ListNode* head) {
        ListNode *mid = head, *mover = head;
        while (mover && mover->next) {
            mover = mover->next->next;
            mid = mid->next;
        }
        return mid;
    }
};
