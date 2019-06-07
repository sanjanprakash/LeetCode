class Solution {
public:
    string reverseWords(string s) {
        int i, j, r = 0, l = 0;
        char temp;
        while (l < s.length()) {
            while (r < s.length() && s[r] != ' ')
                r++;
            i = l;
            j = r-1;
            while (i < j) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            r++;
            l = r;
        }
        return s;
    }
};
