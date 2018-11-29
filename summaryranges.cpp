class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0)
            return ans;
        int i = 1, count = 1;
        string x = to_string(nums[0]);
        while (i < nums.size()) {
            if (nums[i] - nums[i-1] != 1) {
                if (count > 1)
                    x += "->" + to_string(nums[i-1]);
                ans.push_back(x);
                x = to_string(nums[i]);
                count = 1;
            }
            else
                count++;
            i++;
        }
        if (count > 1)
            x += "->" + to_string(nums[n-1]);
        ans.push_back(x);
        return ans;
    }
};
