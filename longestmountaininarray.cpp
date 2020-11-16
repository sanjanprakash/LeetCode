class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i = 0, n = A.size();
        int ans = 0, curr;
        if (n > 2) {
            while (i+1 < n) {
                curr = 1;
                while (i+1 < n && A[i+1] > A[i]) {
                    i++;
                    curr++;
                }
                if (i+1 == n)
                    break;
                while (curr > 1 && i+1 < n && A[i+1] < A[i]) {
                    i++;
                    curr++;
                }
                ans = curr > 2 ? max(ans, curr) : ans;
                i = curr > 1 ? i : i+1;
            }
        }
        return ans;
    }
};
