class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i,j,k;
        int num_blanks = 0;
        int freqs[26] = {0};
        if (s1.length() > s2.length())
            return false;
        for (i = 0; i < s1.length(); i++) {
            freqs[s1[i]-'a']++;
            freqs[s2[i]-'a']--;
        }
        i = 0;
        j = s1.length();
        while (j < s2.length()) {
            num_blanks = 0;
            for (k = 0; k < 26; k++) 
                num_blanks = freqs[k] == 0 ? num_blanks+1 : num_blanks;
            if (num_blanks == 26)
                return true;
            freqs[s2[i]-'a']++;
            freqs[s2[j]-'a']--;
            i++;
            j++;
        }
        num_blanks = 0;
        for (k = 0; k < 26; k++) 
            num_blanks = freqs[k] == 0 ? num_blanks+1 : num_blanks;
        return num_blanks == 26;
    }
};
