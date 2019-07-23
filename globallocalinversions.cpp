class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int i, n = A.size();
        for (i = 0; i < n; i++) {
            if (abs(i-A[i]) > 1)
                return false;
        }
        return true;
    }
};
