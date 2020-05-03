class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> freqs;
        for (char &x : magazine)
            freqs[x]++;
        for (char &x : ransomNote) {
            freqs[x]--;
            if (freqs[x] < 0)
                return false;
        }
        return true;
    }
};
