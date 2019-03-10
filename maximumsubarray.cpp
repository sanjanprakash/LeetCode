class Solution {
public:
    int crossSubarray(vector<int> nums, int l, int m, int r) {
        int i;
        int lsum = 0, rsum = 0;
        int lmax = INT_MIN, rmax = INT_MIN;
        i = m;
        while (i >= l) {
            lsum += nums[i];
            lmax = max(lmax,lsum);
            i--;
        }
        i = m+1;
        while (i <= r) {
            rsum += nums[i];
            rmax = max(rmax,rsum);
            i++;
        }
        return lmax+rmax;
    }
    
    int maxSumSubarray(vector<int> nums, int l, int r) {
        if (l < r) {
            int m = l + (r-l)/2;
            int left = maxSumSubarray(nums,l,m);
            int right = maxSumSubarray(nums,m+1,r);
            int cross = crossSubarray(nums,l,m,r);
            int ans = max(cross,max(left,right));
            return ans;
        }
        return nums[l];
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSumSubarray(nums,0,nums.size()-1);    
    }
};
