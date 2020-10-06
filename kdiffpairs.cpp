class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0, dup = 0;
        unordered_map<int, int> freqs;
        for (int &x : nums)
            freqs[x]++;
        for (auto &x : freqs) {
            if (x.second > 1)
                dup++;
            if (freqs.count(x.first + k))
                ans++;
            if (freqs.count(x.first - k))
                ans++;
        }
        return k ? ans/2 : dup;
    }
};
