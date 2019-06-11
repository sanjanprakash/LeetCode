class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i;
        vector<int> cum_sum(nums.size()+1,0);
        map<int,int> mods;
        if (nums.size() < 2)
            return false;
        if (abs(k) == 1)
            return true;
        if (k) {
            for (i = 0; i < nums.size(); i++) {
                if (i < nums.size()-1 && nums[i] == 0 && nums[i+1] == 0)
                    return true;
                cum_sum[i+1] += ((cum_sum[i]+nums[i])%k);
            }
            for (i = 1; i < nums.size()+1; i++) {
                if (i > 1 && cum_sum[i] == 0 && nums[i-1])
                    return true;
                if (mods[cum_sum[i]] && nums[i-1]%k)
                    return true;
                mods[cum_sum[i]]++;
            }
        }
        else {
            for (i = 0; i < nums.size()-1; i++) {
                if (nums[i] == 0 && nums[i+1] == 0)
                    return true;
            }
        }
        return false;
    }
};
