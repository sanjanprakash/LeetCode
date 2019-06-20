class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int i;
        int big = INT_MIN, small = INT_MAX;
        for (i = 0; i < A.size(); i++) {
            if (big < A[i])
                big = A[i];
            if (small > A[i])
                small = A[i];
        }
        return max(big-small-2*K, 0);
    }
};
