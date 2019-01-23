class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int ans = 0;
        int *arr = new int[K];
        int i, cumsum = 0;
        for (i = 0; i < K; i++)
            arr[i] = 0;
        for (i = 0; i < A.size(); i++) {
            cumsum += A[i];
            arr[((cumsum % K) + K) % K]++;
        }
        for (i = 0; i < K; i++) {
            if (arr[i] > 1)
                ans += (arr[i]*(arr[i]-1))/2;
        }
        ans += arr[0];
        return ans;
    }
};
