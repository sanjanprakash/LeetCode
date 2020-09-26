class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int i, n = timeSeries.size();
        int ans = duration; 
        for (i = 1; i < n; i++)
            ans += min(duration, timeSeries[i]-timeSeries[i-1]);
        return n ? ans : 0;
    }
};
