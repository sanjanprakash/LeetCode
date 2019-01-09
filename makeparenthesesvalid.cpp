class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> St;
        int i;
        int ans = 0;
        for (i = 0; i < S.length(); i++) {
            if (S[i] == '(')
                St.push(S[i]);
            else {
                if (St.empty())
                    ans++;
                else
                    St.pop();
            }
        }
        return ans + St.size();
    }
};
