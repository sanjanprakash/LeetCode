class Solution {
private:
    unordered_map<string,bool> dp;
public:
    bool found(string a, unordered_set<string> &words) {
        int i, n = a.length();
        bool small_find;
        string small = "";
        if (dp.find(a) != dp.end())
            return dp[a];
        if (words.count(a))
            return true;
        for (i = 0; i < n; i++) {
            small += a[i];
            if (words.count(small)) {
                small_find = found(a.substr(i+1,n-i-1),words);
                if (small_find)
                    return true;
            }
        }
        dp[a] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordlist;
        for (auto &x : wordDict)
            wordlist.insert(x);
        return found(s,wordlist);
    }
};
