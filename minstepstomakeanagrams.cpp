class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        unordered_map<char,int> freqs;
        for (auto &x : s)
            freqs[x]++;
        for (auto &x : t)
            freqs[x]--;
        for (auto &x : freqs)
            ans += abs(x.second);
        return ans/2;
    }
};
