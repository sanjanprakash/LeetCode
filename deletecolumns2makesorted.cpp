class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int i,j;
        char c;
        int ans = 0;
        if (A[0].length()) {
            for (i = 0; i < A[0].length(); i++) { 
                c = A[0][i];
                for (j = 1; j < A.size(); j++) {
                    if (A[j][i] < c) {
                        ans++;
                        break;
                    }
                    c = A[j][i];
                }
            }
        }
        return ans;
    }
};
