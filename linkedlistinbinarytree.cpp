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
    bool helper(ListNode *curr, TreeNode *root) {
        if (!curr)
            return true;
        if (!root)
            return false;
        if (root->val != curr->val)
            return false;
        return helper(curr->next, root->left) || helper(curr->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)
            return false;
        return helper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
