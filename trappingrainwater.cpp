class Solution {
public:
    int trap(vector<int>& height) {
        int i, n = height.size();
        int ans = 0, best;
        vector<int> diff(n,0);
        if (n) {
            best = max(0,height[0]);
            for (i = 1; i < n-1; i++) {
                if (height[i] >= best) 
                    best = height[i];                
                else
                    diff[i] = best-height[i];
            }
            best = max(0,height[n-1]);
            for (i = n-2; i > 0; i--) {
                if (height[i] >= best) {
                    diff[i] = 0;
                    best = height[i];
                }
                else
                    diff[i] = min(diff[i],best-height[i]);
            }
            for (int &x : diff)
                ans += x;
        }
        return ans;
    }
};
