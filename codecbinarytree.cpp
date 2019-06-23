/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int i, size;
        bool first = true;
        string ans = "";
        queue<TreeNode *> Q;
        TreeNode *ptr;
        if (root) {
            Q.push(root);
            ans += to_string(root->val);
            while (!Q.empty()) {
                size = Q.size();
                while (size) {
                    ptr = Q.front();
                    Q.pop();
                    if (ptr) {
                        Q.push(ptr->left);
                        Q.push(ptr->right);
                        if (!first)
                            ans += "," + to_string(ptr->val);
                    }
                    else
                        ans += "," + to_string(INT_MIN);
                    size--;
                    first = false;
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int num;
        vector<int> nodes;
        stringstream ss(data);
        while (ss >> num) {
            nodes.push_back(num);
            if (ss.peek() == ',')
                ss.ignore();
        }
        return helper(nodes);
    }
    
    TreeNode *helper(vector<int> arr) {
        int i = 0;
        TreeNode *root = NULL;
        queue<reference_wrapper<TreeNode *> > Q;
        Q.push(root);
        while (i < arr.size()) {
            TreeNode *&curr = Q.front();
            Q.pop();
            if (arr[i] != INT_MIN) {
                curr = new TreeNode(arr[i]);
                Q.push(curr->left);
                Q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};
/*
 Your Codec object will be instantiated and called as such:
 Codec codec;
 codec.deserialize(codec.serialize(root));
*/
