class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        int curr = -1;
        while (curr == -1 && i < n) {
            if (nums[i] == 1)
                curr = i;
            i++;
        }
        while (i < n) {
            if (nums[i] == 1) {
                if (i-curr-1 < k)
                    return false;
                else
                    curr = i;
            }
            i++;
        }
        return true;
    }
};
