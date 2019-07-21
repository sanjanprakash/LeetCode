class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        vector<vector<int> > freqs(10,vector<int>(10,0));
        for (auto &x : dominoes) {
            if (!freqs[x[0]][x[1]] && !freqs[x[1]][x[0]])
                freqs[x[0]][x[1]]++;
            else if (freqs[x[0]][x[1]])
                freqs[x[0]][x[1]]++;
            else
                freqs[x[1]][x[0]]++;
        }
        for (auto &x : freqs) {
            for (auto &y : x) {
                if (y > 1)
                    ans += (y*(y-1))/2;
            }
        }
        return ans;
    }
};
