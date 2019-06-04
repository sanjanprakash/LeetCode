class Solution {
public:
    string removeDuplicates(string S) {
        int i = 1;
        string ans = "";
        stack<char> stk;
        stk.push(S[0]);
        while (i < S.length()) {
            if (!stk.empty() && S[i] == stk.top())
                stk.pop();
            else
                stk.push(S[i]);
            i++;
        }
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
