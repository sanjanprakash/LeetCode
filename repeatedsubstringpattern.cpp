class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l = s.length();
        string dup = s+s;
        return dup.substr(1, 2*l-2).find(s) != -1;
    }
};
