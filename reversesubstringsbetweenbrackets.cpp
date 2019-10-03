class Solution {
public:
    string reverseParentheses(string s) {
        bool curr = false;
        string ans = "", temp;
        stack<pair<string,bool> > st;
        for (auto &x : s) {
            temp = x;
            if (x == '(') {
                curr = !curr;
                st.push({temp,curr});
            }
            else if (x != ')')
                st.push({temp,curr});
            else {
                temp = "";
                while(st.top().first != "(") {
                    if (curr)
                        temp = temp + st.top().first;
                    else
                        temp = st.top().first + temp;
                    st.pop();
                }
                st.pop();
                curr = !curr;
                st.push({temp,curr});
            }
        }
        while (!st.empty()) {
            if (st.top().second)
                ans = ans + st.top().first;
            else
                ans = st.top().first + ans;
            st.pop();
        }
        return ans;
    }
};
