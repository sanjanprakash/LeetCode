class Solution {
public:
    void helper (vector<string> &res, string temp, int left, int right) {
        if (left == 0 && right == 0)
            res.push_back(temp);
        if (left != 0)
            helper(res,temp + '(',left-1,right);
        if (right != 0 && right > left)
            helper(res,temp + ')',left,right-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,"",n,n);
        return ans;
    }
};
