class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 1, n = A.size();
        while (i != n - 1) {
            if (A[i] > A[i+1])
                break;
            i++;
        }
        return i;
    }
};
