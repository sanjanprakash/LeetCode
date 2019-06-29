class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int i, j;
        vector<string> ans;
        map<char,char> mapping;
        map<char,char> rev_mapping;
        for (i = 0; i < words.size(); i++) {
            if (words[i].length() == pattern.length()) {
                for (j = 0; j < pattern.length(); j++) {
                    if (mapping[pattern[j]] == NULL && rev_mapping[words[i][j]] == NULL) {
                        mapping[pattern[j]] = words[i][j];
                        rev_mapping[words[i][j]] = pattern[j];
                    }
                    else if (mapping[pattern[j]] != words[i][j] || rev_mapping[words[i][j]] != pattern[j]) 
                        break;
                }
                if (j == pattern.length())
                    ans.push_back(words[i]);
            }
            mapping.clear();
            rev_mapping.clear();
        }
        return ans;
    }
};
