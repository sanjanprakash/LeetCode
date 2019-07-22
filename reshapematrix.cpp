class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int i,j,ans_r = 0, ans_c = 0;
        vector<vector<int> > ans(r,vector<int>(c));
        if (r*c != nums.size()*nums[0].size()) 
            return nums;
        for (i = 0; i < nums.size(); i++) {
            for (j = 0; j < nums[0].size(); j++) {
                ans[ans_r][ans_c] = nums[i][j];
                ans_c++;
                if (ans_c == c) {
                    ans_r++;
                    ans_c = 0;
                }
            }
        }
        return ans;
    }
};
