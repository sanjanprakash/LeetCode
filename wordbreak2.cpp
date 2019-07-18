class Solution {
private:
    unordered_map<int,vector<string> > dp;
public:
    vector<string> breaker(string s, int last, unordered_set<string>& words) {
        int i;
        string small;
        vector<string> res, temp, blank(1,"");
        if (last == 0)
            return blank;
        if (dp.find(last) != dp.end()) 
            return dp[last];
        for (i = 0; i < last; i++) {
            small = s.substr(i,last-i);
            if (words.count(small)) {
                temp = breaker(s,i,words);
                for (auto &x : temp) {
                    if (x.length() == 0)
                        res.push_back(small);
                    else
                        res.push_back(x+" "+small);
                }
            }
        }
        dp[last] = res;
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordlist;        
        for (auto &x : wordDict) 
            wordlist.insert(x);
        return breaker(s,s.length(),wordlist);
    }
};
