class Solution {
private:
    int dp[100][100][100];
public:    
    int helper(vector<int> &boxes, int l, int r, int k) {
        int i;
        if (l > r)
            return 0;
        if (dp[l][r][k])
            return dp[l][r][k];
        dp[l][r][k] = helper(boxes,l,r-1,0) + (k+1)*(k+1);
        for (i = l; i < r; i++) {
            if (boxes[i] == boxes[r])
                dp[l][r][k] = max(dp[l][r][k],helper(boxes,l,i,k+1) + helper(boxes,i+1,r-1,0));
        }
        return dp[l][r][k];
    }
    
    int removeBoxes(vector<int>& boxes) {
        return helper(boxes,0,boxes.size()-1,0);
    }
};
