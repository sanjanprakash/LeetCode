class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i, n = days[days.size()-1];
        vector<int> dp(n+1, 0);
        for (int &day : days)
            dp[day] = INT_MAX;
        for (i = 1; i <= n; i++) {
            if (dp[i] == 0)
                dp[i] = dp[i-1];
            else
                dp[i] = min({dp[max(0, i-1)]+costs[0], dp[max(0, i-7)]+costs[1], dp[max(0, i-30)]+costs[2]});
        }
        return dp[n];
    }
};
