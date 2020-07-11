class Solution {
public:    
    vector<vector<int>> subsets(vector<int>& nums) {
        int i, n = nums.size();
        vector<vector<int>> ans;
        ans.push_back({});
        for (int x : nums) {
            vector<vector<int>> neo;
            for (auto y : ans) {
                y.push_back(x);
                neo.push_back(y);
            }
            for (auto &y : neo) 
                ans.push_back(y);
        }
        return ans;
    }
};
