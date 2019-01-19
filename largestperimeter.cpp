class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int i = A.size() - 1;
        bool flag = false;
        sort(A.begin(), A.end());
        while (i > 1 && !flag) {
            if (A[i] + A[i-1] > A[i-2] && A[i-1] + A[i-2] > A[i] && A[i] + A[i-2] > A[i-1])
                flag = true;
            i--;
        }
        return flag ? A[i+1] + A[i] + A[i-1] : 0; 
    }
};
