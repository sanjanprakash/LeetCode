class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string ans = "";
        unordered_map<char,bool> seen;
        unordered_map<char,int> freqs;        
        for (auto &x : s)
            freqs[x]++;
        for (auto &x : s) {
            if (!seen[x]) {
                while (x < ans.back() && freqs[ans.back()] > 0) {
                    seen[ans.back()] = false;
                    ans.pop_back();
                }
                ans += x;
                seen[x] = true;
            }
            freqs[x]--;
        }
        return ans;
    }
};
