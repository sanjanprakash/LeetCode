class Solution {
public:
    int histogram_rect(vector<int>& rects) {
        int i, n = rects.size(), idx;
        int ans = 0;
        stack<int> S;
        for (i = 0; i < n; i++) {
            while (!S.empty() && rects[S.top()] > rects[i]) {
                idx = S.top();
                S.pop();
                if (!S.empty())
                    ans = max(ans,rects[idx]*(i-S.top()-1));
                else
                    ans = max(ans,rects[idx]*i);
            }
            S.push(i);
        }
        while (!S.empty()) {
            idx = S.top();
            S.pop();
            if (S.empty())
                ans = max(ans,rects[idx]*n);
            else
                ans = max(ans,rects[idx]*(n-S.top()-1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int i,j;
        int m = matrix.size(), n;
        int ans = 0;
        if (m) {
            n = matrix[0].size();
            vector<int> hist(n,0);
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    if (matrix[i][j] == '1')
                        hist[j]++;
                    else
                        hist[j] = 0;
                }
                ans = max(ans,histogram_rect(hist));
            }
        }
        return ans;
    }
};
