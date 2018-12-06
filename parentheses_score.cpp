class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        int i, open = 1, close = 0;
        for (i = 1; i < S.length(); i++) {
            if (S[i] == '(')
                open++;
            else {
                close++;
                if (S[i-1] == '(')
                    ans += pow(2,open-close);
            }
        }
        return ans;
    }
};
