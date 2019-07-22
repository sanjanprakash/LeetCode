class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        map<int,int> freqs;
        for (auto &x : time)
            freqs[x%60]++;
        ans += freqs[0]*(freqs[0]-1)/2;
        ans += freqs[30]*(freqs[30]-1)/2;
        freqs[0] = 0;
        for (auto &x : freqs) {
            if (x.first >= 30)
                break;
            else
                ans += x.second*(freqs[60-x.first]);
        }
        return ans;
    }
};
