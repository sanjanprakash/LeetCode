class Solution {
public:
    string reverseWords(string s) {
        int i;
        string ans = "", uno = "";
        vector<string> words;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && uno.length()) {
                words.push_back(uno);
                uno.clear();
            }
            else if (s[i] != ' ')
                uno += s[i];
        }
        if (uno.length())
            words.push_back(uno);
        for (i = words.size()-1; i > -1; i--) {
            ans += words[i];
            if (i > 0)
                ans += " ";
        }
        return ans;
    }
};
