class Solution {
public:
    string removeOuterParentheses(string S) {
        int i = 0;
        string ans = "";
        stack<char> stk;
        while (i < S.length()) {
            stk.push(S[i]);
            i++;
            while(!stk.empty()) {
                if (S[i] == '(') 
                    stk.push(S[i]);
                else
                    stk.pop();
                if (!stk.empty())
                    ans += S[i];
                i++;
            }
        }
        return ans;
    }
};
