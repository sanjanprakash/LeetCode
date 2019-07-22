class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i, back = 0;
        stack<char> st;
        for (auto &x : S) {
            if (x == '#') {
                if (!st.empty())   
                    st.pop();
            }
            else
                st.push(x);
        }
        for (i = T.length()-1; i > -1; i--) {
            if (T[i] == '#')
                back++;
            else {
                if (back) {
                    back--;
                    continue;
                }
                else {
                    if (st.empty() || st.top() != T[i])
                        return false;
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
