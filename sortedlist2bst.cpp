/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return listToBST(head,NULL);
    }
    
    TreeNode* listToBST(ListNode *start, ListNode *end) {
        if (start == NULL || start == end)
            return NULL;
        cout << start->val << endl;
        if (start->next == end) {
            TreeNode *root = new TreeNode(start->val);
            return root;
        }
        ListNode *mid = start, *doubler = start;
        while (doubler != end && doubler->next != end) {
            mid = mid->next;
            doubler = doubler->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = listToBST(start,mid);
        root->right = listToBST(mid->next,end);
        return root;
    }
};
