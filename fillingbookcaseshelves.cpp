class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int i, j, n = books.size();
        int tallest, width;
        vector<int> dp(n+1,0);
        for (i = 0; i < n; i++) {
            tallest = 0;
            width = 0;
            for (j = i; j >= 0; j--) {
                tallest = max(tallest,books[j][1]);
                width += books[j][0];
                if (width > shelf_width)
                    break;
                dp[i+1] = dp[i+1] == 0 ? dp[j]+tallest : min(dp[i+1],dp[j]+tallest);
            }
        }
        return dp[n];
    }
};
