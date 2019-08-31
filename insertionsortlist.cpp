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
    ListNode* insertionSortList(ListNode* head) {
        int smallest;
        ListNode *root = new ListNode(INT_MIN), *curr, *move, *prev, *temp;
        root->next = head;
        curr = root;
        while (curr) {
            move = curr;
            smallest = INT_MAX;
            prev = NULL;
            while (move->next) {
                if (smallest > move->next->val) {
                    smallest = move->next->val;
                    prev = move;
                }
                move = move->next;
            }
            if (prev && prev != curr) {
                temp = prev->next->next;
                prev->next->next = curr->next;
                curr->next = prev->next;
                prev->next = temp;
            }
            
            curr = curr->next;
        }
        return root->next;
    }
};
