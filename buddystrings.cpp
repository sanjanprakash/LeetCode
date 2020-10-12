class Solution {
public:
    bool buddyStrings(string A, string B) {
        int i, mismatches = 0;
        int m = A.length(), n = B.length();
        vector<int> freqs(26, 0);
        if (m != n)
            return false;
        if (A == B) {
            for (i = 0; i < m; i++) {
                freqs[A[i]-'a']++;
                if (freqs[A[i]-'a'] > 1)
                    return true;
            }
            return false;
        }
        for (i = 0; i < m; i++) {
            freqs[A[i]-'a']++;
            freqs[B[i]-'a']--;
            mismatches += (A[i] == B[i]) ? 0 : 1;
        }
        for (i = 0; i < 26; i++) {
            if (freqs[i] != 0)
                return false;
        }
        return mismatches == 2;
    }
};
