class Solution {
public:
    int crossMaxSubarray(vector<int> nums, int l, int m, int r) {
        int i;
        int lsum = 0, lmax = INT_MIN;
        int rsum = 0, rmax = INT_MIN;
        for (i = m; i >= l; i--) {
            lsum += nums[i];
            lmax = max(lmax,lsum);
        }
        for (i = m+1; i <= r; i++) {
            rsum += nums[i];
            rmax = max(rmax,rsum);
        }
        return lmax+rmax;
    }
    
    int maxSubarray(vector<int> nums, int l, int r) {
        if (l < r) {
            int m = l + (r-l)/2;
            int left = maxSubarray(nums,l,m);
            int right = maxSubarray(nums,m+1,r);
            int cross = crossMaxSubarray(nums,l,m,r);
            return max(cross,max(left,right));
        }
        return nums[l];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i,j;
        if (n > 1) {
            vector<int> profits = vector<int>(n-1);
            for (i = 1; i < n; i++)
                profits[i-1] = prices[i] - prices[i-1];
            return max(0,maxSubarray(profits,0,n-2));
        }
        return 0;
    }
};
