class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i, n = pattern.length();
        string word;
        vector<string> words;
        unordered_map<char, string> P2S;
        unordered_map<string, char> S2P;
        istringstream ss(str);
        while (ss >> word) 
            words.push_back(word);
        if (words.size() != n)
            return false;
        for (i = 0; i < n; i++) {
            if (P2S.find(pattern[i]) == P2S.end() && S2P.find(words[i]) == S2P.end()) {
                P2S[pattern[i]] = words[i];
                S2P[words[i]] = pattern[i];
            }
            else if (P2S[pattern[i]] != words[i] || S2P[words[i]] != pattern[i])
                return false;
        }
        return true;
    }
};
