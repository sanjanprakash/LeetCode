class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int i, j;
        int n = A.size();
        vector<string> ans;
        int freqs[26], per_word[26];
        for (i = 0; i < 26; i++)
            freqs[i] = 101;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 26; j++)
                per_word[j] = 0;
            for (j = 0; j < A[i].length(); j++) 
                per_word[A[i][j] - 97]++;
            for (j = 0; j < 26; j++) {
                if (per_word[j] < freqs[j])
                    freqs[j] = per_word[j];
            }
        }
        for (i = 0; i < 26; i++) {
            while (freqs[i]--) 
                ans.push_back(string(1,'a'+i));
        }
        return ans;
    }
};
