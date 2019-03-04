class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int prev = -1;
        int rep = 1;
        int i,j = -1;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != prev) {
                j++;
                rep = 1;
            }
            else {
                rep++;
                if (rep < 3)
                    j++;
            }
            nums[j] = nums[i];
            prev = nums[i];
        }
        return j+1;
    }
};
