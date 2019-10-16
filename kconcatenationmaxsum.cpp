class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int i, n = arr.size();
        long long int sum = 0;
        long long int best_pre = INT_MIN, best_suf = INT_MIN;
        long long int ans1 = INT_MIN, ans2, ans3;
        int mod = 1000000007;
        vector<long long int> prefix_sum(n,0), suffix_sum(n,0);
        for (i = 0; i < n; i++) {
            sum = (sum+arr[i])%mod;
            ans1 = max(sum,ans1);
            if (sum < 0)
                sum = 0;
        }
        prefix_sum[0] = arr[0];
        suffix_sum[n-1] = arr[n-1];
        for (i = 1; i < n; i++) {
            prefix_sum[i] = (prefix_sum[i-1] + arr[i])%mod;
            suffix_sum[n-i-1] = (suffix_sum[n-i] + arr[n-i-1])%mod;
        }
        for (i = 0; i < n; i++) {
            best_pre = max(best_pre,prefix_sum[i]);
            best_suf = max(best_suf,suffix_sum[i]);
        }
        if (prefix_sum[n-1] <= 0 && ans1 <= 0)
            return 0;
        best_pre = best_pre % mod;
        best_suf = best_suf % mod;
        ans2 = (best_pre+best_suf)%mod;
        ans3 = ((k-2)*(prefix_sum[n-1]%mod))%mod;
        ans3 = (ans3+ans2)%mod;
        ans2 = max(ans1,ans2);
        return max(ans2,ans3);
    }
};
