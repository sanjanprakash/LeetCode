class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int i, n = hours.size();
        int start = 1, dist = INT_MIN;
        vector<int> prefix(n+1,0), best(n+1,INT_MIN);
        for (auto &x : hours) {
            if (x > 8)
                x = 1;
            else
                x = -1;
        }
        for (i = 1; i <= n; i++)
            prefix[i] = prefix[i-1] + hours[i-1];
        best[n] = prefix[n];
        for (i = n-1; i > -1; i--)
            best[i] = max(best[i+1],prefix[i]);
        for (i = 1; i <= n; i++) {
            if (prefix[start-1] < best[i])
                dist = max(dist,i-start+1);
            else
                start++;
        }
        return dist == INT_MIN ? 0 : dist;
    }
};
