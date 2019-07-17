class Solution {
public:
    bool found(string a, unordered_set<string> &words, bool prev_found) {
        int i, n = a.length();
        bool small_find;
        string small = "";
        for (i = 0; i < n; i++) {
            small += a[i];
            if (words.count(small)) {
                if (i == n-1)
                    return prev_found;
                small_find = found(a.substr(i+1,n-i-1),words,true);
                if (small_find)
                    return true;
            }
        }
        return false;
    }    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> wordlist;
        for (auto &x : words)
            wordlist.insert(x);
        for (auto &x : words) {
            if (found(x,wordlist,false))
                ans.push_back(x);
        }
        return ans;
    }
};
