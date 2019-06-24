class Solution {
public:
    bool isAnagram(string s, string t) {
        int i = 0, blanks = 0;
        int freqs[26] = {0};
        while (i < s.length() && i < t.length()) {
            freqs[s[i]-'a']++;
            freqs[t[i]-'a']--;
            i++;
        }
        for (i = 0; i < 26; i++) {
            if (freqs[i] == 0)
                blanks++;
        }
        return s.length() == t.length() ? blanks == 26 : false;
    }
};
