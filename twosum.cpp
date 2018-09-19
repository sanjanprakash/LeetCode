class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int comp,i,j,n = nums.size();
        vector<int>ans;
        bool flag = false;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    flag = true;
                    break;    
                }
            }
            if (flag == true)
                break;
        }
        if (flag == true) {
            ans.push_back(i);
            ans.push_back(j);
        }
        return ans;
    }
};
