class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int m = s.length(), n = t.length();
        while (j < n) {
            if (s[i] == t[j]) 
                i++;
            if (i == m)
                break;
            j++;
        }
        return i == m;
    }
};
