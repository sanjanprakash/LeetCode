class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() == 0)
            return 0;
        sort(A.begin(),A.end());
        int i, ori_sum = 0;
        int x = A[0],prev = A[0];
        for (i = 0; i < A.size(); i++)
            ori_sum += A[i];
        for (i = 1; i < A.size(); i++) {
            if (A[i] <= prev) {
                prev++;
                x += prev;
            }
            else {
                x += A[i];
                prev = A[i];
            }
        }
        return x - ori_sum;
    }
};
