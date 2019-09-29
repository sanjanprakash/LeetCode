class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freqs, freq_keys;
        for (auto &x : arr)
            freqs[x]++;
        for (auto &x : freqs) {
            if (freq_keys[x.second])
                return false;
            freq_keys[x.second] = x.first+1001;
        }
        return true;
    }
};
