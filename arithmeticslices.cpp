class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i, cnt = 0;
        int ans = 0;
        vector<int> diffs;
        for (i = 1; i < A.size(); i++) {
            diffs.push_back(A[i]-A[i-1]);
            if (i > 1) {
                if (diffs[i-1] == diffs[i-2])
                    cnt++;
                else {
                    ans += cnt*(cnt+1)/2;
                    cnt = 0;
                }
            }
        }
        return cnt > 0 ? ans + cnt*(cnt+1)/2 : ans;
    }
};
