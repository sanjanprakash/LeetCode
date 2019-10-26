class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = 0, n = s.length();
        int unique = 0, longest = 0;
        unordered_map<char,int> freqs;
        while (r < n) {
            freqs[s[r]]++;
            if (freqs[s[r++]] == 1)
                unique++;
            while (unique > 2) {
                freqs[s[l]]--;
                if (!freqs[s[l++]])
                    unique--;
            }
            longest = max(longest,r-l);
        }
        return longest;
    }
};
