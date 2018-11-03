class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>X;
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (X.find(nums[i]) == X.end() || i == 0) 
                X[nums[i]] = 1;
            else if (i != 0)
                return true;
        }
        return false;
    }
};
