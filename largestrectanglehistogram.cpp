class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i, n = heights.size();
        int idx;
        int ans = 0;
        stack<int> S;
        for (i = 0; i < n; i++) {
            while (!S.empty() && heights[S.top()] > heights[i]) {
                idx = S.top();
                S.pop();
                if (!S.empty())
                    ans = max(ans,heights[idx]*(i-S.top()-1));
                else
                    ans = max(ans,heights[idx]*i);
            }
            S.push(i);
        }
        while (!S.empty()) {
            idx = S.top();
            S.pop();
            if (!S.empty())
                ans = max(ans,heights[idx]*(n-S.top()-1));
            else
                ans = max(ans,heights[idx]*n);
        }
        return ans;
    }
};
