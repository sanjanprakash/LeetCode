class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i, j, n = triangle.size();
        int ans = INT_MAX;
        vector<int> sum(n, triangle[0][0]);
        for (i = 1; i < n; i++) {
            sum[i] = sum[i-1] + triangle[i][i];
            for (j = i-1; j > 0; j--) 
                sum[j] = triangle[i][j] + min(sum[j], sum[j-1]);
            sum[0] = sum[0] + triangle[i][0];
        }
        for (int x : sum)
            ans = min(ans, x);
        return ans;
    }
};
