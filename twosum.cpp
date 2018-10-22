class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() > 2){
            map<int,int> sums;
            for(int i = 0; i < nums.size(); i++){
                int diff = target - nums[i];
                if(sums.find(diff) == sums.end())
                    sums[nums[i]] = i;
                else {
                    ans.push_back(sums[diff]);
                    ans.push_back(i);
                    return ans;
                }
            }
        }
        ans.push_back(0);
        ans.push_back(1);
        return ans;
    }
};
