class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int i,n = calories.size();
        int ans = 0, score;
        vector<int> dp(n+1,0);
        for (i = 1; i <= n; i++)
            dp[i] = dp[i-1] + calories[i-1];
        for (i = 1; i <= n; i++) {
            if (i >= k) {
                score = dp[i] - dp[i-k];
                if (score > upper)
                    ans++;
                else if (score < lower)
                    ans--;
            }
        }
        return ans;
    }
};
