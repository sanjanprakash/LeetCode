class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int i, n = nums.size();
        int ans = 0, uniques = 0;
        vector<int> ids(10001,-1);
        vector<pair<int,int> > elems;
        if (!n)
            return 0;
        for (i = 0; i < n; i++) {
            if (ids[nums[i]] == -1) {
                elems.push_back(make_pair(nums[i],nums[i]));
                ids[nums[i]] = uniques;
                uniques++;
            }
            else
                elems[ids[nums[i]]].second += nums[i];
        }
        sort(elems.begin(),elems.end());
        vector<int> dp(uniques+1,0);
        dp[1] = elems[0].second;
        for (i = 2; i <= uniques; i++) {
            dp[i] = max(dp[i-1],elems[i-1].second + (elems[i-1].first == elems[i-2].first+1 ? dp[i-2] : dp[i-1]));
        }
        return dp[uniques];
    }
};
