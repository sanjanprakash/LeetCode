class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int i, ans = 0;
        vector<int> freqs(26,0);
        for (auto &x : chars)
            freqs[x-'a']++;
        for (auto &x : words) {
            for (i = 0; i < x.length(); i++) {
                freqs[x[i]-'a']--;
                if (freqs[x[i]-'a'] < 0)
                    break;
            }
            if (i == x.length()) {
                ans += i;
                i--;
            }
            while (i >= 0) {
                freqs[x[i]-'a']++;
                i--;
            }
        }
        return ans;
    }
};
