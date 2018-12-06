class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        int i, close = 1, open = 0;
        for (i = 1; i < S.length(); i++) {
            if (S[i] == '(')
                close++;
            else {
                open++;
                if (S[i-1] == '(')
                    ans += pow(2,close-open);
            }
        }
        return ans;
    }
};
