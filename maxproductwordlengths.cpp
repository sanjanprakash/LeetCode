class Solution {
public:
    int maxProduct(vector<string>& words) {
        int i, j, k, ans = INT_MIN;
        bool share;
        long mask, char_mask;
        vector<long> masks;
        if (words.size()) {
            for (auto &word : words) {
                mask = 0;
                for (char c : word)
                    mask |= (1 << (c-'a'));
                masks.push_back(mask);
            }

            for (i = 0; i < words.size()-1; i++) {
                for (j = i+1; j < words.size(); j++) {
                    share = false;
                    for (k = 0; k < 26; k++) {
                        char_mask = (1 << k);
                        if (masks[i]&char_mask && masks[j]&char_mask) {
                            share = true;
                            break;
                        }
                    }
                    if (!share)
                        ans = max(ans, int(words[i].length()*words[j].length()));
                }
            }
        }
        
        return ans == INT_MIN ? 0 : ans;
    }
};
