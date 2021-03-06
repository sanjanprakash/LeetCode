class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j, n = A.size();
        for (j = 0; j < n; j++) {
            if (A[j]%2 == 0) {
                swap(A[i], A[j]);
                i++;
            }
        }
        return A;
    }
};
