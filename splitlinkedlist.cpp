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
        vector<int> sizes(k,0);
        vector<ListNode *> ans;
        ListNode *curr = root, *start, *prev;
        while (curr) {
            curr = curr->next;
            len++;
        }
        size = len/k;
        rem = len%k;
        for (i = 0; i < k; i++)
            sizes[i] += size;
        for (i = 0; i < k && rem; i++) {
            sizes[i]++;
            rem--;
        }
        curr = root;
        for (i = 0; i < k; i++) {
            size = 0;
            start = curr;
            while (size < sizes[i]) {
                prev = curr;
                curr = curr->next;
                size++;
            }
            prev->next = NULL;
            ans.push_back(start);
        }
        return ans;
    }
};
