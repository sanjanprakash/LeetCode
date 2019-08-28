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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum = 0, zero_sum;
        ListNode *curr = head, *prev, *old, *root = new ListNode(0);
        unordered_map<int,ListNode *> cum_sum;
        cum_sum[0] = root;
        root->next = head;
        while (curr) {
            sum += curr->val;
            if (cum_sum.find(sum) == cum_sum.end())
                cum_sum[sum] = curr;
            else {
                prev = cum_sum[sum];
                old = prev;
                zero_sum = sum;
                while (prev->next != curr) {
                    prev = prev->next;
                    zero_sum += prev->val;
                    cum_sum.erase(zero_sum);
                }
                old->next = curr->next;
            }
            curr = curr->next;
        }
        return root->next;
    }
};
