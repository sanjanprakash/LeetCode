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
    void insert(stack<TreeNode *> &S, stack<int> &depth, int d, int num) {
        TreeNode *neo = new TreeNode(num);
        if (d > depth.top()) {
            S.top()->left = neo;
            depth.push(d);
            S.push(neo);
        }
        else {
            while (d <= depth.top()) {
                depth.pop();
                S.pop();
            }
            S.top()->right = neo;
            depth.push(d);
            S.push(neo);
        }
    }
    
    TreeNode* recoverFromPreorder(string S) {
        int i = 0, num = 0;
        int d = 0;
        stack<TreeNode *> stk;
        stack<int> depth;    
        TreeNode *root;
        if (!S.length())
            return NULL;
        while (i < S.length() && S[i] != '-') {
            num *= 10;
            num += (S[i]-'0');
            i++;
        }
        root = new TreeNode(num);
        stk.push(root);
        depth.push(0);
        num = 0;
        while (i < S.length()) {
            if (S[i] == '-') {
                if (num) {
                    insert(stk,depth,d,num);
                    num = 0;
                    d = 0;
                }
                d++;
            }
            else {
                num *= 10;
                num += (S[i]-'0');
            }
            i++;
        }
        if (num) 
            insert(stk,depth,d,num);
        return root;
    }
};
