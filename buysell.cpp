class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i,j;
        int ans = 0;
        for (i = 0; i < n-1; i++) {
            for (j = i+1; j < n; j++) {
                if (prices[i] < prices[j])
                    ans = max(ans,prices[j]-prices[i]);
            }
        }
        return ans;
    }
};
