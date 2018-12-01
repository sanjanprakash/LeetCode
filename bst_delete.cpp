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
    
    void Del(TreeNode *par, TreeNode *ptr, bool left, int key) {
        int temp;
        TreeNode *p = ptr;
        TreeNode *curr;
        bool l = false;
        if (ptr != NULL) {
            if (par == NULL && ptr->val == key) {
                if (ptr->left == NULL) {
                    curr = p->right;
                    while (curr->left != NULL) {
                        l = true;
                        p = curr;
                        curr = curr->left;
                    }
                    temp = curr->val;
                    Del(p,curr,l,temp);
                    ptr->val = temp;
                    return;
                }
                if (ptr->right == NULL) {
                    curr = p->left;
                    l = true;
                    while (curr->right != NULL) {
                        l = false;
                        p = curr;
                        curr = curr->right;
                    }
                    temp = curr->val;
                    Del(p,curr,l,temp);
                    ptr->val = temp;
                    return;
                }
            }
            if (ptr->left == NULL && ptr->right == NULL && ptr->val == key) {
                if (left == true)
                    par->left = NULL;
                else
                    par->right = NULL;
                return;
            }
            if (ptr->left == NULL && ptr->val == key) {
                if (left == true)
                    par->left = ptr->right;
                else
                    par->right = ptr->right;
                return;
            }
            if (ptr->right == NULL && ptr->val == key) {
                if (left == true)
                    par->left = ptr->left;
                else
                    par->right = ptr->left;
                return;
            }
            else {
                if (ptr->val < key)
                    Del(ptr,ptr->right,false,key);
                else if (ptr->val > key)
                    Del(ptr,ptr->left,true,key);
                else {
                    curr = ptr->right;
                    while (curr->left != NULL) {
                        l = true;
                        p = curr;
                        curr = curr->left;
                    }
                    temp = curr->val;
                    Del(p,curr,l,temp);
                    ptr->val = temp;
                }
                return;
            }
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root != NULL) {
            if (root->val == key && root->left == NULL && root->right == NULL)
                root = NULL;
            else
                Del(NULL,root,false,key);
        }
        return root;
    }
};
