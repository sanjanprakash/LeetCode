class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i = 0, n = palindrome.size();
        if (n == 1)
            return "";
        while (palindrome[i] == 'a' || i == n/2)
            i++;
        if (i == n)
            palindrome[i-1] = 'b';
        else
            palindrome[i] = 'a';
        return palindrome;
    }
};
