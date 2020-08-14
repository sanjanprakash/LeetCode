class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length(), ans = 0;
        unordered_map<char, int> freqs;
        for (char x : s)
            freqs[x]++;
        for (auto &x : freqs) 
            ans += (x.second/2)*2;
        return min(ans+1, n);
    }
};
