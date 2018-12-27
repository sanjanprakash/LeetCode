class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(),A.end());
        int i;
        for (i = 0; i < A.size()-1; i++) {
            if (A[i] == A[i+1])
                return A[i];
        }
    }
};
