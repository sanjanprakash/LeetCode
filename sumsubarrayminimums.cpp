class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int i,j,n = A.size();
        int ans = 0;
        vector<int> dp(n,0);
        stack<int> S;
        if (n) {
            for (i = 0; i < n; i++) {
                while (!S.empty() && A[S.top()] > A[i])
                    S.pop();
                j = !S.empty() ? S.top() : -1;
                dp[i] = dp[(n+j)%n] + (i-j)*A[i];
                S.push(i);
            }
            for (i = 0; i < n; i++)
                ans = (ans+dp[i])%1000000007;
        }
        return ans;
    }
};
