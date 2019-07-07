class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int i,j,k,len;
        int l,r,ldp,rdp;
        int n = nums.size();
        if (!n)
            return n;
        vector<vector<int> > dp(n,vector<int>(n,0));
        for (len = 0; len <= n; len++) {
            for (i = 0,j = i+len; i < n && j < n ; i++,j++) {
                for (k = i; k <= j; k++) {
                    l = i-1 >= 0 ? nums[i-1] : 1;
                    r = j+1 < n ? nums[j+1] : 1;
                    ldp = k-1 >= 0 ? dp[i][k-1] : 0;
                    rdp = k+1 < n ? dp[k+1][j] : 0;
                    dp[i][j] = max(dp[i][j],ldp + rdp + l*nums[k]*r);            
                }
            }
        }
        return dp[0][n-1];
    }
};
