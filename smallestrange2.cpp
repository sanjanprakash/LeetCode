class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int i, n = A.size();
        int ans;
        if (n < 2)
            return 0;
        sort(A.begin(),A.end());
        ans = A[n-1]-A[0];
        for (i = 0; i < n-1; i++)
            ans = min(ans,max(A[n-1]-K,A[i]+K) - min(A[0]+K,A[i+1]-K));
        return ans;        
    }
};
