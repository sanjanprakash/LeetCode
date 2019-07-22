class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for (auto &x : s) {
            if (x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U')
                st.push(x);
        }
        for (auto &x : s) {
            if (x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U') {
                x = st.top();
                st.pop();
            }
        }
        return s;
    }
};
