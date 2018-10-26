class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>check;
        int ans = 0,i;
        check.push(-1);
        for (i = 0; i < s.length(); i++) {
            if (check.top() != -1 && s[check.top()] == '(' && s[i] == ')') {
                check.pop();
                ans = max(ans,i - check.top());
            }
            else
                check.push(i);
        }
        return ans;
    }
};
