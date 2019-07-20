class Solution {
public:
    unordered_set<string> helper(string &exp, int &ind) {
        int n = exp.length();
        string word;
        unordered_set<string> ans, smaller, temp;
        while (ind < n) {
            if (exp[ind] == '{') {
                ind++;
                smaller = helper(exp,ind);
                ind++;
                if (smaller.size()) {
                    if (!ans.size())
                        ans = smaller;
                    else {
                        temp = ans;
                        ans.clear();
                        for (auto &x : temp) {
                            for (auto &y : smaller)
                                ans.insert(x+y);
                        }
                    }
                }
            }
            else if (exp[ind] == ',') {
                ind++;
                smaller = helper(exp,ind);
                for (auto &x : smaller)
                    ans.insert(x);
            }
            else if (exp[ind] == '}')
                return ans;
            else {
                word = "";
                while (ind < n && exp[ind] >= 'a' && exp[ind] <= 'z') {
                    word += exp[ind];
                    ind++;
                }
                if (ans.size()) {
                    temp = ans;
                    ans.clear();
                    for (auto &x : temp)
                        ans.insert(x+word);
                }
                else
                    ans.insert(word);
            }
        }
        return ans;
    }
    
    vector<string> braceExpansionII(string expression) {
        int id = 0;
        vector<string> ans;
        unordered_set<string> all = helper(expression,id);
        for (auto &x : all)
            ans.push_back(x);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
