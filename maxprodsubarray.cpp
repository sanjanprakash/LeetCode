class Solution {
public:    
    int maxProduct(vector<int>& nums) {
        int minim = 1,maxim = 1;
        int i,ans = nums[0];
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) 
                swap(minim,maxim);
            minim = min(nums[i],minim*nums[i]);
            maxim = max(nums[i],maxim*nums[i]);
            ans = max(maxim,ans);
        }
        return ans;
    }
};
