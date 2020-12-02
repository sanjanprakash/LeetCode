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
private:
    int l;
    ListNode *list;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode *curr = head;
        l = 0;
        list = head;
        while (curr) {
            curr = curr->next;
            l++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = rand()%l;
        ListNode *curr = list;
        while (n--)
            curr = curr->next;
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
