class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, n = s.length(), m = t.length();
        int start, end, smallest = INT_MAX;
        int match = 0;
        string ans = "";
        unordered_map<char,int> freqs_s, freqs_t;
        if (m <= n) {
            for (auto &x : t)
                freqs_t[x]++;
            while (r < n) {
                freqs_s[s[r]]++;
                if (freqs_t.find(s[r]) != freqs_t.end() && freqs_s[s[r]] == freqs_t[s[r]]) {
                    match++;
                }
                while (l <= r && match == freqs_t.size()) {
                    if (r-l+1 < smallest) {
                        smallest = r-l+1;
                        start = l;
                        end = r;
                    }
                    freqs_s[s[l]]--;
                    if (freqs_t.find(s[l]) != freqs_t.end() && freqs_s[s[l]] < freqs_t[s[l]])
                        match--;
                    l++;
                }
                r++;                
            }
            if (smallest != INT_MAX)
                ans = s.substr(start,smallest);
        }
        return ans;
    }
};
