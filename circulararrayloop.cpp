class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int i, n = nums.size();
        for (i = 0; i < n; i++) {
            if (helper(nums,i))
                return true;
        }
        return false;
    }
    
    bool helper(vector<int>& nums, int id) {
        int n = nums.size(), next;
        int old = nums[id];
        if (!nums[id])
            return true;
        next = (((id+nums[id])%n)+n)%n;
        if (next == id || nums[id]*nums[next] < 0)
            return false;
        nums[id] = 0;
        if (helper(nums,next))
            return true;
        nums[id] = old;
        return false;
    }
};
