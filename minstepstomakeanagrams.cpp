class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        vector<int> freqs(26,0);
        for (auto &x : s)
            freqs[x-'a']++;
        for (auto &x : t)
            freqs[x-'a']--;
        for (auto &x : freqs)
            ans += abs(x);
        return ans/2;
    }
};
