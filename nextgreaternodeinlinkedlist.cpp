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
    vector<int> nextLargerNodes(ListNode* head) {
        int i = 0,len = 0;
        ListNode *curr = head;
        stack<pair<int,int> > S;
        while (curr) {
            curr = curr->next;
            len++;
        }
        vector<int> ans(len,0);
        curr = head;
        while (i < len) {
            if (!S.empty() && curr->val > S.top().second) {
                while (!S.empty() && curr->val > S.top().second) {
                    ans[S.top().first] = curr->val;
                    S.pop();
                }   
            }
            S.push(make_pair(i,curr->val));
            curr = curr->next;
            i++;
        }
        return ans;
    }
};
