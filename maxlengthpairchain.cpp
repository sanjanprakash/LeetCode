class Solution {
public:
    bool compare(vector<int> A, vector<int> B) {
        return A[1] < B[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int i, j;
        int ans = -1, n = pairs.size();
        vector<int> dp(n,1);
        sort(pairs.begin(),pairs.end());
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
