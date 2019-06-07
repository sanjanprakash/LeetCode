class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int i = 0, j;
        if (A.size() > 1) {
            while (i < A.size()-1 && A[i] == A[i+1])
                i++;
            if (i < A.size()-1) {
                if (A[i] < A[i+1]) {
                    for (j = i+1; j < A.size()-1; j++) {
                        if (A[j] > A[j+1])
                            return false;
                    }
                }
                else {
                    for (j = 1; j < A.size()-1; j++) {
                        if (A[j] < A[j+1])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
