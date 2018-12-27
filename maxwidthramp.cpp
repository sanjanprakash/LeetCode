class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans = 0;
        int i;
        stack<int> S;
        S.push(0);
        for (i = 1; i < A.size(); i++) {
            if (A[i] < A[S.top()])
                S.push(i);
        }
        for (i = A.size() - 1; i > 0; i--) {
            while (!S.empty() && A[i] >= A[S.top()]) {
                ans = ans > i - S.top() ? ans : i - S.top();
                S.pop();
            }
        }
        return ans;
    }
};
