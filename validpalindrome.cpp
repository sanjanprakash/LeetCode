class Solution {
public:
    bool isChar(char x) {
        if (int(x) > 47 && int(x) < 58)
            return true;
        if (int(x) > 64 && int(x) < 91)
            return true;
        if (int(x) > 96 && int(x) < 123)
            return true;
        return false;
    }
    
    bool isNum(char x) {
        if (int(x) > 47 && int(x) < 58)
            return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0,j = n - 1;
        while (i < j) {
            if (isChar(s[i]) && isChar(s[j])) {
                if (isNum(s[i]) == isNum(s[j])) {
                    if (s[i] == s[j] || int(s[i]) + 32 == int(s[j]) || int(s[i]) == int(s[j]) + 32) {
                        i++;
                        j--;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else if (!isChar(s[i]))
                i++;
            else if (!isChar(s[j]))
                j--;
        }
        return true;
    }
};
