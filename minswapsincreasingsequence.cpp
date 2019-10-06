class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int i, n = A.size();
        int swap, no_swap;
        int prev_swap = 1, prev_no_swap = 0;
        if (n > 1) {
            for (i = 1; i < n; i++) {
                swap = INT_MAX;
                no_swap = INT_MAX;
                if (A[i] > A[i-1] && B[i] > B[i-1]) {
                    swap = prev_swap+1;
                    no_swap = prev_no_swap;
                }
                if (A[i] > B[i-1] && B[i] > A[i-1]) {
                    no_swap = min(no_swap,prev_swap);
                    swap = min(prev_no_swap,swap)+1;
                }
                prev_swap = swap;
                prev_no_swap = no_swap;
            }
        }
        return min(swap,no_swap);
    }
};
