class Solution {
public:    
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.length(), ans = 0;
        int most = INT_MIN;
        vector<int> freqs(26,0);
        while (r < n) {
            freqs[s[r]-'A']++;
            if (freqs[s[r++]-'A'] > most) 
                most = freqs[s[r-1]-'A'];
            while (l < r && r-l-most > k) 
                freqs[s[l++]-'A']--;
            ans = max(ans,r-l);
        }
        return ans;
    }
};
