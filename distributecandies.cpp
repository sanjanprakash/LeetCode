class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int i;
        int n = candies.size(), unique;
        map<int,int> freqs;
        for (i = 0; i < n; i++)
            freqs[candies[i]]++;
        unique = freqs.size();
        return unique < n/2 ? unique : n/2;
    }
};
