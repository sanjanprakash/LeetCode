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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int i, len = 0;
        int size, rem;
        vector<ListNode *> ans;
        ListNode *curr = root, *prev;
        while (curr) {
            curr = curr->next;
            len++;
        }
        size = len/k;
        rem = len%k;
        curr = root;
        for (i = 0; i < k; i++) {
            len = 0;
            ans.push_back(curr);
            while (len < size) {
                prev = curr;
                curr = curr->next;
                len++;
            }
            if (ans.size() <= rem) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
        }
        return ans;
    }
};
