class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, n = prices.size();
        int ans = 0;
        if (n) {
            int minLeft = prices[0], maxRight = prices[n-1];
            vector<int> left(n+1), right(n+1);
            left[0] = 0;
            right[n] = 0;
            for (i = 1; i < n; i++) {
                left[i] = max(left[i-1], prices[i] - minLeft);
                minLeft = min(minLeft, prices[i]);
            }
            for (i = n-2; i > -1; i--) {
                right[i] = max(right[i+1], maxRight - prices[i]);
                maxRight = max(maxRight, prices[i]);
            }
            for (i = 0; i <= n; i++)
                ans = max(ans, left[i]+right[i]);
        }
        return ans;
    }
};
