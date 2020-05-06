class Solution {
public:
    bool helper(string s1, string s2, int start) {
        int i = start, n = s1.length();
        while (i < n && s1[i] <= s2[i])
            i++;
        return i == n;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        int i = 0, n = s1.length();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        while (i < n && s1[i] == s2[i])
            i++;
        if (i == n)
            return true;
        if (s1[i] <= s2[i])
            return helper(s1, s2, i+1);
        return helper(s2, s1, i+1);
    }
};
