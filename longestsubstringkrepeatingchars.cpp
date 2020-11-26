class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, n = s.length();
        int l, r, curr, geq_k;
        int unique = 0, curr_unique;
        vector<int> freqs(26, 0);
        for (char x : s) {
            if (!freqs[x-'a'])
                unique++;
            freqs[x-'a']++;
        }
        for (curr_unique = 1; curr_unique <= unique; curr_unique++) {
            l = 0;
            r = 0;
            curr = 0;
            geq_k = 0;
            fill(freqs.begin(), freqs.end(), 0);
            while (r < n) {
                if (curr <= curr_unique) {
                    if (!freqs[s[r]-'a'])
                        curr++;
                    freqs[s[r]-'a']++;
                    if (freqs[s[r]-'a'] == k)
                        geq_k++;
                    r++;
                }
                else {
                    if (freqs[s[l]-'a'] == k)
                        geq_k--;
                    freqs[s[l]-'a']--;
                    if (!freqs[s[l]-'a'])
                        curr--;
                    l++;
                }
                if (curr == curr_unique && curr == geq_k)
                    ans = max(ans, r-l);
            }
        }
        return ans;
    }
};
