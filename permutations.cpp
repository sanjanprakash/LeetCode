class Solution {
public:
    
    vector<vector<int> > ans;
    
    void Permuter(vector<int> &nums, int start, int end) {
        int i, temp;
        if (start == end)
            ans.push_back(nums);
        else {
            for (i = start; i <= end; i++) {
                temp = nums[start];
                nums[start] = nums[i];
                nums[i] = temp;
                Permuter(nums,start+1,end);
                temp = nums[start];
                nums[start] = nums[i];
                nums[i] = temp;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        Permuter(nums,0,nums.size()-1);
        return ans;
    }
};
