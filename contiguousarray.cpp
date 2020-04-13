class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i, n = nums.size(), count = 0;
        int ans = 0;
        unordered_map<int, int> subArrCount;
        for (i = 0; i < n; i++) {
            if (nums[i])
                count++;
            else
                count--;
            if (!count)
                ans = i+1;
            else {
                if (subArrCount.find(count) == subArrCount.end())
                    subArrCount[count] = i;
                else
                    ans = max(ans, i-subArrCount[count]);
            }
        }
        return ans;
    }
};
