class Solution {
public:
    void aux(vector<int> nums, vector<vector<int>> &ans, vector<int> &uno, int target, int start) {
        if (target == 0)
            ans.push_back(uno);
        else {
            int i;
            for (i = start; i < nums.size(); i++) {
                if (nums[i] <= target) {
                    uno.push_back(nums[i]);
                    aux(nums,ans,uno,target-nums[i],i);
                    uno.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> oneCombo;
        sort(candidates.begin(),candidates.end());
        aux(candidates,ans,oneCombo,target,0);
        return ans;
    }
};
