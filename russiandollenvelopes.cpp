class Solution {
public:
    bool compare(vector<int> A, vector<int> B) {
        return A[0] < B[0] && A[1] < B[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int i, j;
        int n = envelopes.size(), ans = -1;
        sort(envelopes.begin(),envelopes.end());
        if (n < 2)
            return n;
        vector<int> dp(n,1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
