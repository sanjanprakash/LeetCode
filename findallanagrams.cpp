class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i,j,k;
        int num_blanks = 0;
        int freqs[26] = {0};
        vector<int> ans;
        if (p.length() <= s.length()) {
            for (i = 0; i < p.length(); i++) {
                freqs[p[i]-'a']++;
                freqs[s[i]-'a']--;
            }
            i = 0;
            j = p.length();
            while (j < s.length()) {
                num_blanks = 0;
                for (k = 0; k < 26; k++) 
                    num_blanks = freqs[k] == 0 ? num_blanks+1 : num_blanks;
                if (num_blanks == 26)
                    ans.push_back(i);
                freqs[s[i]-'a']++;
                freqs[s[j]-'a']--;
                i++;
                j++;
            }
            num_blanks = 0;
            for (k = 0; k < 26; k++) 
                num_blanks = freqs[k] == 0 ? num_blanks+1 : num_blanks;
            if (num_blanks == 26)
                ans.push_back(i);
        }
        return ans;    
    }
};
