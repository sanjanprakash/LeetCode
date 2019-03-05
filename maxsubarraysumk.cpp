class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int,int> summer;
        int sum = 0;
        int i;
        int ans = 0;
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k)
                ans = i+1;
            else if (summer.find(sum-k) != summer.end())
                ans = max(ans,i-summer[sum-k]);
            if (summer.find(sum) == summer.end())
                summer[sum] = i;
        }
        return ans;
    }
};
